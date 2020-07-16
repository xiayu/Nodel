#include "ndpch.h"
#include "Buffer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Nodel {
	Ref<VertexBuffer> VertexBuffer::Create(float* verteies, uint32_t size) {
		return CreateRef<OpenGLVertexBuffer>(verteies, size);
	}

	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size) {
		return CreateRef<OpenGLVertexBuffer>(size);
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count) {
		return CreateRef<OpenGLIndexBuffer>(indices, count);
	}
}