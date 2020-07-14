#pragma once
#include "glm/glm.hpp"

namespace Nodel {
	class Shader
	{
	public:
		virtual void Bind() = 0;
		virtual void UnBind() = 0;

		virtual void SetInt(const char* name, int value) = 0;
		virtual void SetIntArray(const char* name, int* values, unsigned int count) = 0;
		virtual void SetFloat(const char* name, float value) = 0;
		virtual void SetFloat3(const char* name, glm::vec3& value) = 0;
		virtual void SetFloat4(const char* name, glm::vec4& value) = 0;
		virtual void SetMat4(const char* name, glm::mat4& value) = 0;

		virtual std::string GetName() const = 0;

		static Ref<Shader> Create(const std::string& filepath);
		static Ref<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);

	};

	class ShaderLibrary {
	public:
		void Add(const std::string& name, Ref<Shader>& shader);
		void Add(Ref<Shader>& shader);
		
		Ref<Shader> Get(const std::string& name);

		Ref<Shader> Load(const std::string& name, const std::string& filepath);

		bool Exists(const std::string& name) const;
	private:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};
}

