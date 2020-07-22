#pragma once
#include "Nodel/Events/MouseEvent.h"
#include "Nodel/Events/WindowsEvent.h"
#include "Nodel/Renderer/Camera.h"
#include "Nodel/Core/TimeStep.h"

namespace Nodel {
	class CameraController
	{
	public:
		CameraController(Ref<Camera> camera, float aspectRatio, bool rotation);

		void OnUpdate(TimeStep ts);
		void OnEvent(Event& e);

		void OnResize(float width, float height);

		Camera& GetCamera() { return *m_Camera; }
		const Camera& GetCamera() const { return *m_Camera; }

		float GetZoomLevel() const { return m_ZoomLevel; }
		void SetZoomLevel(float level) { m_ZoomLevel = level; }
	private:
		bool OnMouseScrolled(MouseScrolleEvent& e);
		bool OnWindowResized(WindowResizedEvent& e);

	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		Ref<Camera> m_Camera;

		bool m_Rotation;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f; 
		float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
	};
}
