#pragma once

#include "Nodel/Core/Base.h"
#include "ndpch.h"

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

#define  ND_EVENT_TYPE(event) \
	const char* GetName() const override{ return #event; }\
	static EventType GetStaticEventType() { return EventType::event; }\
	EventType GetEventType() const override{ return GetStaticEventType(); }
#define  ND_EVENT_CATEGORY(category)\
	int GetCategoryFlags() const override{ return category; }

	class Event {
		friend class EventDispatcher;
	public:
		virtual ~Event() = default;
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

		bool Handled = false;
	};

	class EventDispatcher {
	public:
		EventDispatcher(Event& event):
			m_Event(event)
		{

		}
		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func) {
			if (m_Event.GetEventType() == T::GetStaticEventType()) {
				m_Event.Handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};
}
