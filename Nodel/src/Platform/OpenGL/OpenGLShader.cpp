#include "ndpch.h"
#include "OpenGLShader.h"
#include <fstream>
#include "glad/glad.h"
#include <glm/gtc/type_ptr.hpp>

namespace Nodel {

	static GLenum ShaderTypeFromString(const std::string& type)
	{
		if (type == "vertex")
			return GL_VERTEX_SHADER;
		if (type == "fragment" || type == "pixel")
			return GL_FRAGMENT_SHADER;
		if (type == "geometry")
			return GL_GEOMETRY_SHADER;

		ND_ASSERT(false, "Unknown shader type!");
		return 0;
	}

	OpenGLShader::OpenGLShader(const std::string& filepath)
	{
		std::string& source = ReadFile(filepath);
		std::unordered_map<GLenum, std::string> shaderSources = PreProcess(source);
		Compile(shaderSources);

		auto lastSlash = filepath.find_last_of("/\\");
		lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
		auto lastDot = filepath.rfind('.');
		auto count = lastDot == std::string::npos ? filepath.size() - lastSlash : lastDot - lastSlash;
		m_Name = filepath.substr(lastSlash, count);

	}

	OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc):
		m_Name(name)
	{
		std::unordered_map<GLenum, std::string> shaderSources;
		shaderSources[GL_VERTEX_SHADER] = vertexSrc;
		shaderSources[GL_FRAGMENT_SHADER] = fragmentSrc;
		Compile(shaderSources);
	}

	OpenGLShader::~OpenGLShader() {
		glDeleteProgram(m_RendererID);
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(m_RendererID);
	}

	void OpenGLShader::UnBind()
	{
		glUseProgram(0);
	}

	void OpenGLShader::SetInt(const char* name, int value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name);
		glUniform1i(location, value);
	}

	void OpenGLShader::SetIntArray(const char* name, int* values, unsigned int count)
	{
		GLint location = glGetUniformLocation(m_RendererID, name);
		glUniform1iv(location, count, values);
	}

	void OpenGLShader::SetFloat(const char* name, float value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name);
		glUniform1f(location, value);
	}

	void OpenGLShader::SetFloat3(const char* name, const glm::vec3& value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name);
		glUniform3f(location, value.x, value.y, value.z);
	}

	void OpenGLShader::SetFloat4(const char* name, const glm::vec4& value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name);
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void OpenGLShader::SetMat4(const char* name, const glm::mat4& value)
	{
		GLint location = glGetUniformLocation(m_RendererID, name);
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}

	std::string OpenGLShader::ReadFile(const std::string& filepath)
	{
		std::string result;
		std::ifstream in(filepath, std::ios::in | std::ios::binary);
		if (in) {
			in.seekg(0, std::ios::end);
			size_t size = in.tellg();
			if (size != -1) {
				result.resize(size);
				in.seekg(0, std::ios::beg);
				in.read(&result[0], size);
				in.close();
			}
			else {
				ND_ERROR("file:{0} read error!", filepath);
			}
		}
		else {
			ND_ERROR("file:{0} open error!", filepath);
		}
		return result;
	}

	std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string& source)
	{
		std::unordered_map<unsigned int, std::string> shaderSources;
		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = source.find(typeToken, 0);
		while (pos != std::string::npos) {
			size_t eol = source.find_first_of("\r\n", pos);
			ND_ASSERT(eol != std::string::npos, "Synatax error!");
			size_t begin = pos + typeTokenLength + 1;
			std::string type = source.substr(begin, eol - begin);
			size_t nextLinePos = source.find_first_not_of("\r\n", eol);
			ND_ASSERT(nextLinePos != std::string::npos, "Synatax error!");
			pos = source.find(typeToken, nextLinePos);
			shaderSources[ShaderTypeFromString(type)] = (pos == std::string::npos) ? source.substr(nextLinePos) : source.substr(nextLinePos, pos - nextLinePos);
		}
		return shaderSources;
	}

	void OpenGLShader::Compile(std::unordered_map<GLenum, std::string>& shaderSources)
	{
		GLuint program = glCreateProgram();
		std::vector<GLenum> glShaderIDs;
		int glShaderIDIndex = 0;
		for (auto& kv : shaderSources) {
			GLenum  type = kv.first;
			const std::string& source = kv.second;
			GLuint shader = glCreateShader(type);
			const GLchar* sourceCstr = source.c_str();
			glShaderSource(shader, 1, &sourceCstr, 0);
			glCompileShader(shader);
			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shader);

				ND_ERROR("{0}", infoLog.data());
				ND_ASSERT(false, "Shader compilation failure!");
				break;
			}

			glAttachShader(program, shader);
			glShaderIDs.push_back(shader);
		}
		m_RendererID = program;

		glLinkProgram(program);
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(program);
			
			for (auto id : glShaderIDs)
				glDeleteShader(id);

			ND_ERROR("{0}", infoLog.data());
			ND_ASSERT(false, "Shader link failure!");
			return;
		}

		for (auto id : glShaderIDs)
		{
			glDetachShader(program, id);
			glDeleteShader(id);
		}
	}

}