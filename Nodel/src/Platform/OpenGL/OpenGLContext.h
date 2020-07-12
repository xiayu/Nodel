#pragma once
#include "Nodel/Renderer/GraphicsContext.h"
struct GLFWwindow;

namespace Nodel {
	class OpenGLContext :
		public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;

		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;

	};
}

