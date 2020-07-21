#include "ndpch.h"
#include "RenderCommand.h"
namespace Nodel {
	Uni<RenderAPI> RenderCommand::s_RenderAPI = RenderAPI::Create();
}