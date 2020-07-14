#include "ndpch.h"
#include "Shader.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace Nodel {

	Ref<Shader> Shader::Create(const std::string& filepath)
	{
		return CreateRef<OpenGLShader>(filepath);
	}

	Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		return CreateRef<OpenGLShader>(name, vertexSrc, fragmentSrc);
	}

	void ShaderLibrary::Add(const std::string& name, Ref<Shader>& shader)
	{
		ND_ASSERT(!Exists(name), "shader {0} already exist!", name);
		m_Shaders[name] = shader;
	}

	void ShaderLibrary::Add(Ref<Shader>& shader)
	{
		Add(shader->GetName(), shader);
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& filepath)
	{
		Ref<Shader> shader = Shader::Create(filepath);
		Add(name, shader);
		return shader;
	}

	bool ShaderLibrary::Exists(const std::string& name) const
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}

}
