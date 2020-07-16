#pragma once
#include "Nodel/Renderer/Buffer.h"

namespace Nodel {
	class OpenGLVertexBuffer :public VertexBuffer {

	public:
		OpenGLVertexBuffer(uint32_t size);
		OpenGLVertexBuffer(const void* verteies, uint32_t size);

		~OpenGLVertexBuffer();

		virtual void Bind() override;
		virtual void UnBind() override;

		virtual void SetData(const void* data, uint32_t size) override;

		virtual const BufferLayout& GetLayout() const override {
			return m_Layout;
		}
		virtual void SetLayout(const BufferLayout& layout) override {
			m_Layout = layout;
		};
	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;

	};

	class OpenGLIndexBuffer :public IndexBuffer {

	public:
		OpenGLIndexBuffer(uint32_t* indeices, uint32_t count);
		~OpenGLIndexBuffer();

		virtual void Bind() override;
		virtual void Unbind() override;

		virtual uint32_t GetCount() const override {
			return m_Count;
		}
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;

	};
}
