#pragma once
#include "Nodel/Events/Event.h"

namespace Nodel {
	class MouseMoveEvent :public Event {
	public:
		MouseMoveEvent(float x, float y):
			m_MouseX(x), m_MouseY(y)
		{

		}
		ND_EVENT_CATEGORY(EventCategoryMouse)
		ND_EVENT_TYPE(MouseMoved)

		int GetMouseX() const { return m_MouseX; }
		int GetMouseY() const { return m_MouseY; }

		std::string ToString() const {
			std::stringstream ss;
			ss << "MouseMoveEvent:(" << m_MouseX << "," << m_MouseY << ")";
			return ss.str();
		}

	private:
		float m_MouseX, m_MouseY;
	};

	class MouseScrolleEvent :public Event {
	public:
		MouseScrolleEvent(float x, float y):
			x_Offset(x), y_Offset(y){
		}
		float GetXOffset() const { return x_Offset; }
		float GetYOffset() const { return y_Offset; }
		std::string ToString() const {
			std::stringstream ss;
			ss << "MouseScrolledEvent:(" << x_Offset << "," << y_Offset << ")";
			return ss.str();
		}
		ND_EVENT_TYPE(MouseScrolled)
		ND_EVENT_CATEGORY(EventCategoryMouse)

	private:
		float x_Offset, y_Offset;
	};

	class MouseButtonEvent :public Event {
	protected:
		MouseButtonEvent(int buttoncode):
			m_MouseCode(buttoncode)
		{

		}
		ND_EVENT_CATEGORY(EventCategoryMouseButton)
		int m_MouseCode;
	};

	class MouseButtonPressedEvent :public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int buttoncode) :
			MouseButtonEvent(buttoncode)
		{

		}

		std::string ToString() const {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent:" << m_MouseCode;
			return ss.str();
		}
		ND_EVENT_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent :public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int buttoncode) :
			MouseButtonEvent(buttoncode)
		{

		}

		std::string ToString() const {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent:" << m_MouseCode;
			return ss.str();
		}
		ND_EVENT_TYPE(MouseButtonReleased)
	};
}
