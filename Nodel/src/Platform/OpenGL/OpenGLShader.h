#pragma once
#include "Nodel/Renderer/Shader.h"
namespace Nodel{
	typedef unsigned int GLenum;
	class OpenGLShader :public Shader
	{
	public:
		OpenGLShader(const std::string& filepath);
		OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);

		virtual ~OpenGLShader();

		virtual void Bind() override;
		virtual void UnBind() override;

		virtual void SetInt(const char* name, int value) override;
		virtual void SetIntArray(const char* name, int* values, unsigned int count) override;
		virtual void SetFloat(const char* name, float value) override;
		virtual void SetFloat3(const char* name, const glm::vec3& value) override;
		virtual void SetFloat4(const char* name, const glm::vec4& value) override;
		virtual void SetMat4(const char* name, const glm::mat4& value) override;

		virtual std::string GetName() const override {
			return m_Name;
		}

	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		void Compile(std::unordered_map<GLenum, std::string>& shaderSources);

	private:
		uint32_t m_RendererID;
		std::string m_Name;
	};
}

