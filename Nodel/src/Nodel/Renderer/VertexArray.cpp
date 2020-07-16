#include "ndpch.h"
#include "VertexArray.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Nodel {
	Ref<VertexArray> VertexArray::Create() {
		return CreateRef<OpenGLVertexArray>();
	}
}
