#include "ndpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace Nodel {

	OpenGLVertexArray::OpenGLVertexArray() {

	}

	OpenGLVertexArray::~OpenGLVertexArray() {

	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexbuffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexbuffer)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	std::vector<Nodel::Ref<Nodel::VertexBuffer>>& OpenGLVertexArray::GetVertexBuffers() const
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	Nodel::Ref<Nodel::IndexBuffer>& OpenGLVertexArray::GetIndexBuffer() const
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

}
