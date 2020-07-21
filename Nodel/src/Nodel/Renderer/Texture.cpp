#include "ndpch.h"
#include "Texture.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Nodel {

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		return CreateRef<OpenGLTexture2D>(width, height);
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		return CreateRef<OpenGLTexture2D>(path);
	}

}
