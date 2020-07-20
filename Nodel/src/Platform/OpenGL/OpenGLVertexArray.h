#pragma once
#include "Nodel/Renderer/VertexArray.h"

namespace Nodel {
	class OpenGLVertexArray :public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		virtual void Bind() override; 
		virtual void Unbind() override;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexbuffer) override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexbuffer) override;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const override { return m_VertexBuffers;};
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const override {
			return m_IndexBuffer;
		};

	private:
		uint32_t m_RendererID;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;
		uint32_t m_VertexBufferIndex = 0;
	};
}

