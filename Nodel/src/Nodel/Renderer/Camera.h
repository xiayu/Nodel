#pragma once
#include <glm/glm.hpp>

namespace Nodel {
	class  Camera
	{
	public:
		enum class CameraType {
			Orthographic, Perspective
		};

		Camera() :
			m_ViewMatrix(1.0f), m_ProjectionMatrix(1.0f), m_ViewProjectionMatrix(1.0f) {
		}

		virtual ~Camera() = default;
		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateViewMatrix(); }

		float GetRotation() const { return m_Rotation; }
		void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
		virtual CameraType GetType() const = 0;

	protected:
		virtual void RecalculateViewMatrix() = 0;

	protected:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;
	};

	class OrthographicCamera :public Camera {
	public:
		using Camera::Camera;

		void SetProjection(float left, float right, float bottom, float top);

		virtual CameraType GetType() const override {
			return Camera::CameraType::Orthographic;
		};

	protected:
		virtual void RecalculateViewMatrix() override;

	};

	class PerspectiveCamera :public Camera {
	public:
		PerspectiveCamera() {
		}

		virtual CameraType GetType() const override {
			return Camera::CameraType::Perspective;
		}
	};
}
