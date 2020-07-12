#include "ndpch.h"
#include "WindowsWindow.h"
#include "Nodel/Events/Event.h"
#include "Nodel/Events/KeyEvent.h"
#include "Nodel/Events/MouseEvent.h"
#include "Nodel/Events/WindowsEvent.h"

namespace Nodel {

	static void GLFWErrorCallback(int error, const char* description)
	{
		ND_ERROR("GLFW Error ({0}): {1}", error, description);
	}
	
	static bool s_glfwInited = false;

	WindowsWindow::WindowsWindow(const WindowProp& prop)
	{
		init(prop);
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::init(const WindowProp& prop)
	{
		window_data.m_Title = prop.Title;
		window_data.m_Width = prop.Width;
		window_data.m_Height = prop.Height;

		ND_INFO("create window: {0} ({1}, {2})", prop.Title, prop.Width, prop.Height);

		if (!s_glfwInited)
		{
			int success = glfwInit();
			ND_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_glfwInited = true;
		}

		m_NativeWindow = glfwCreateWindow((int)prop.Width, (int)prop.Height, prop.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_NativeWindow);
		glfwSetWindowUserPointer(m_NativeWindow, &window_data);
		SetVSync(true);

		// Set GLFW callbacks

		glfwSetWindowSizeCallback(m_NativeWindow, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.m_Width = width;
				data.m_Height = height;

				WindowResizedEvent event(width, height);
				data.callback(event);
			});

		glfwSetWindowCloseCallback(m_NativeWindow, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.callback(event);
			});

		glfwSetKeyCallback(m_NativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.callback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.callback(event);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(m_NativeWindow, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.callback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.callback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(m_NativeWindow, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolleEvent event((float)xOffset, (float)yOffset);
				data.callback(event);
			});

		glfwSetCursorPosCallback(m_NativeWindow, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMoveEvent event((float)xPos, (float)yPos);
				data.callback(event);
			});
	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(m_NativeWindow);
	}

	void WindowsWindow::SetVSync(bool vsync)
	{
		if (vsync) {
			glfwSwapInterval(1);
		}
		else
			glfwSwapInterval(0);
		window_data.m_Vsync = vsync;
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_NativeWindow);
	}


}
