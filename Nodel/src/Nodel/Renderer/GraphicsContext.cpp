#include "ndpch.h"
#include "GraphicsContext.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Nodel {
	Uni<GraphicsContext> GraphicsContext::Create(void* window) {
		return CreateUni<OpenGLContext>(static_cast<GLFWwindow*>(window));
	}
}