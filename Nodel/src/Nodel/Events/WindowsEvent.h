#pragma once
#include "Nodel/Events/Event.h"

namespace Nodel {
	class WindowCloseEvent :public Event {
	public:
		WindowCloseEvent() {

		}
		ND_EVENT_TYPE(WindowClose)
		ND_EVENT_CATEGORY(EventCategoryWindow)
		std::string ToString() const {
			std::stringstream ss;
			ss << "WindowCloseEvent";
			return ss.str();
		}
	};

	class WindowFocusEvent :public Event {
	public:
		WindowFocusEvent() {

		}
		ND_EVENT_TYPE(WindowFocus)
		ND_EVENT_CATEGORY(EventCategoryWindow)
		std::string ToString() const {
			std::stringstream ss;
			ss << "WindowFocusEvent";
			return ss.str();
		}
	};

	class WindowLostFocusEvent :public Event {
	public:
		WindowLostFocusEvent() {

		}
		ND_EVENT_TYPE(WindowLostFocus)
		ND_EVENT_CATEGORY(EventCategoryWindow)
		std::string ToString() const {
			std::stringstream ss;
			ss << "WindowLostFocusEvent";
			return ss.str();
		}
	};

	class WindowResizedEvent :public Event {
	public:
		WindowResizedEvent(unsigned int width, unsigned int height):
			m_Width(width), m_Height(height)
		{

		}
		
		unsigned int GetWidth() const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }

		ND_EVENT_TYPE(WindowResized)
		ND_EVENT_CATEGORY(EventCategoryWindow)

		std::string ToString() const {
			std::stringstream ss;
			ss << "WindowResizedEvent";
			return ss.str();
		}

	private:
		unsigned int m_Width, m_Height;
	};
}
