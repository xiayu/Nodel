#pragma once

#include "Nodel/Core/Base.h"
#include <string>

namespace Nodel {
	enum class EventType {
		AppTick, AppUpdate, AppRender,
		WindowClose, WindowResized, WindowFocus, WindowLostFocus, WindowMoved,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		KeyPressed, keyReleased, KeyTyped,
	};
	
	enum EventCategory {
		None = 0,
		EventCategoryApp = BIT(0),
		EventCategoryWindow = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

	class Event {
	public:
		virtual ~Event() = default;
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

	};

	class EventDispatcher {
	public:
		EventDispatcher(Event& event):
			m_Event(event)
		{

		}
		bool Dispatch() {

		}
	private:
		Event& m_Event;
	};
}
