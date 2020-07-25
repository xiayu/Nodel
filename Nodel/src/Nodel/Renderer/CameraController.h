#pragma once
#include "Nodel/Events/MouseEvent.h"
#include "Nodel/Events/WindowsEvent.h"
#include "Nodel/Renderer/Camera.h"
#include "Nodel/Core/TimeStep.h"

namespace Nodel {
	class CameraController
	{
	public:
		CameraController();

		CameraController(Camera& camera);

		void SetCamera(Camera& camera);

		void OnUpdate(TimeStep ts);
		void OnEvent(Event& e);

		void OnResize(float width, float height);

		Camera& GetCamera() { return m_Camera; }
		const Camera& GetCamera() const { return m_Camera; }

		float GetZoomLevel() const { return m_ZoomLevel; }
		void SetZoomLevel(float level) { m_ZoomLevel = level; }

	protected:
		bool OnMouseScrolled(MouseScrolleEvent& e);
		bool OnWindowResized(WindowResizedEvent& e);

	protected:
		Camera& m_Camera;

		float m_AspectRatio = 1.0f;
		float m_ZoomLevel = 1.0f;
		bool m_Rotation = false;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f; 
		float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
	};
}
