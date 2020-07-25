#include "ndpch.h"
#include "Renderer.h"
#include "RenderCommand.h"
#include "Renderer2D.h"

namespace Nodel {

	void Renderer::Init()
	{
		RenderCommand::Init();
		Renderer2D::Init();
	}

	void Renderer::Shutdown()
	{

	}

	void Renderer::OnWindowResized(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewPort(0, 0, width, height);
	}

	void Renderer::BeginScene()
	{

	}

	void Renderer::EndScene()
	{

	}

	void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexarray)
	{
		shader->Bind();
		vertexarray->Bind();
		RenderCommand::DrawIndexed(vertexarray);
	}

}