#pragma once
#include "Nodel/Renderer/RenderAPI.h"
#include "Nodel/Renderer/Shader.h"
#include "Nodel/Renderer/VertexArray.h"

namespace Nodel {
	class Renderer {
	public:
		static void Init();
		static void Shutdown();

		static void OnWindowResized(uint32_t width, uint32_t height);

		static void BeginScene();
		static void EndScene();

		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexarray);

		static RenderAPI::API GetAPI() { return RenderAPI::GetAPI(); }

	private:
	};
}
