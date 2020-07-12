#pragma once
#include "Nodel/Core/Window.h"
#include "Nodel/Renderer/GraphicsContext.h"

#include "GLFW/glfw3.h"

namespace Nodel {
	class WindowsWindow :public Window
	{
	public:
		WindowsWindow(const WindowProp& prop);
		~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return window_data.m_Width; }
		unsigned int GetHeight() const override { return window_data.m_Height; }

		void SetVSync(bool vsync) override;
		bool GetVSync() const override { return window_data.m_Vsync; }

		void SetEventCallback(const EventCallbackFn& func) { window_data.callback = func; }

		void* GetNativeWindow() const override { return m_NativeWindow; }


	private:
		void init(const WindowProp& prop);
		void shutdown();
	private:
		GLFWwindow* m_NativeWindow;

		struct WindowData {
			std::string m_Title;
			unsigned int m_Width, m_Height;
			bool m_Vsync;
			EventCallbackFn callback;
		};

		WindowData window_data;

		Uni<GraphicsContext> m_Context;
	};
}

