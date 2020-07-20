#pragma once
#include "Nodel/Renderer/ShaderDataType.h"

namespace Nodel {
	struct BufferElement {
		std::string m_Name;
		ShaderDataType m_Type;
		uint32_t m_Size;
		uint32_t m_Offset;
		bool m_Normalized;

		BufferElement() = default;
		BufferElement(ShaderDataType type, std::string& name, bool normalized = false) :
			m_Type(type), m_Name(name), m_Size(ShaderDataTypeSize(type)), m_Offset(0), m_Normalized(normalized) {
		}
	};

	class BufferLayout {
	public:
		BufferLayout() {}
		BufferLayout(std::initializer_list<BufferElement>& elements) :
			m_Elements(elements) {
			CalculateOffsetAndStride();
		}

		uint32_t GetStride() const { return m_Stride; }
		const std::vector<BufferElement>& GetElements() const { return m_Elements; }

		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); };
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); };
		std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); };
		std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); };

	private:

		void CalculateOffsetAndStride() {
			size_t offset = 0;
			m_Stride = 0;
			for (BufferElement element : m_Elements) {
				element.m_Offset =(uint32_t)offset;
				offset += element.m_Size;
				m_Stride += element.m_Size;
			}
		}

		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride;
	};

	class VertexBuffer {
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;
		virtual void UnBind() = 0;
		virtual void SetData(const void* data, uint32_t size) = 0;

		virtual const BufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;

		static Ref<VertexBuffer> Create(uint32_t size);
		static Ref<VertexBuffer> Create(float* verteies, uint32_t size);

	};

	class IndexBuffer {
	public:
		virtual ~IndexBuffer() = default;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual uint32_t GetCount() const = 0;
		static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t count);
	};
}
