#include "ndpch.h"
#include "RenderAPI.h"
#include "Platform/OpenGL/OpenGLRenderAPI.h"

namespace Nodel {

	RenderAPI::API RenderAPI::s_API = RenderAPI::API::OpenGL;

	Uni<RenderAPI> RenderAPI::Create()
	{
		return CreateUni<OpenGLRenderAPI>();
	}
}