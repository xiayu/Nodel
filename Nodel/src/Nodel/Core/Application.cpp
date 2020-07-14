#include "ndpch.h"
#include "Application.h"

#include "glad/glad.h"

namespace Nodel {

	Application* Application::s_Instance = nullptr;

	Application::Application(const char* name /*= "Nodel App"*/):
		m_Running(true)
	{
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(ND_EVENT_BIND_FUNC(Application::OnEvent));

		m_ImguiLayer = new ImGuiLayer();
		PushOverlay(m_ImguiLayer);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_ImguiLayer->Begin();
			{
				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
			}
			m_ImguiLayer->End();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& event) {
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(ND_EVENT_BIND_FUNC(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizedEvent>(ND_EVENT_BIND_FUNC(Application::OnWindowResized));

		for (Layer* layer : m_LayerStack) {
			if(event.Handled)
				break;
			layer->OnEvent(event);
		}

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& event) {
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResized(WindowResizedEvent& event) {
		ND_INFO("OnWindowResized:({0}, {1})", event.GetWidth(), event.GetHeight());
		return true;
	}

}