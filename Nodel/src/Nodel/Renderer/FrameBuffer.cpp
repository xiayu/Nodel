#include "ndpch.h"
#include "FrameBuffer.h"
#include "Platform/OpenGL/OpenGLFrameBuffer.h"

namespace Nodel {

	Nodel::Ref<FrameBuffer> FrameBuffer::Create(const FrameBufferSpecification& spec)
	{
		return CreateRef<OpenGLFrameBuffer>(spec);
	}

}
