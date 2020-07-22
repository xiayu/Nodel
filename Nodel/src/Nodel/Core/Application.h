#pragma once
#include "Nodel/Core/Base.h"
#include "Nodel/Core/Window.h"
#include "Nodel/Events/Event.h"
#include "Nodel/Events/WindowsEvent.h"
#include "Nodel/Core/LayerStack.h"
#include "Nodel/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Nodel {
	class Application {
	public:
		friend int ::main(int argc, char** argv);

		Application(const char* name = "Nodel App");
		virtual ~Application();
		virtual void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		Window& GetWindow() const { return *m_Window; }

		ImGuiLayer* GetImguiLayer() const { return m_ImguiLayer; }

		static Application& GetInstance() { return *s_Instance; }

	private:
		void Run();
		virtual bool OnWindowClose(WindowCloseEvent& e);
		virtual bool OnWindowResized(WindowResizedEvent& e);
	private:
		std::unique_ptr<Window> m_Window;

		bool m_Running;
		static Application* s_Instance;
		LayerStack m_LayerStack;

		ImGuiLayer* m_ImguiLayer;
		float m_LastFrameTime;

	};

	Nodel::Application* CreateApplication();
}

