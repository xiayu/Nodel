#pragma once
#include "Nodel/Renderer/VertexArray.h"

namespace Nodel {
	class OpenGLVertexArray :public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexbuffer) override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexbuffer) override;

		virtual std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const override;
		virtual Ref<IndexBuffer>& GetIndexBuffer() const override;
	private:
		uint32_t m_RendererID;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;

	};
}

