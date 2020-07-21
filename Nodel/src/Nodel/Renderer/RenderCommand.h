#pragma once
#include "Nodel/Renderer/RenderAPI.h"

namespace Nodel {
	class RenderCommand {
	public:
		static void Init() {
			s_RenderAPI->Init();
		}

		static void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
			s_RenderAPI->SetViewPort(x, y, width, height);
		}

		static void SetClearColor(const glm::vec4& color) {
			s_RenderAPI->SetClearColor(color);
		}

		static void Clear() {
			s_RenderAPI->Clear();
		}

		static void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t count = 0) {
			s_RenderAPI->DrawIndexed(vertexArray, count);
		}

	private:
		static Uni<RenderAPI> s_RenderAPI;
	};
}
