#pragma once
#include "Nodel/Events/Event.h"

namespace Nodel {
	class KeyEvent :public Event {
		inline const int GetKeyCode() const { return m_keycode; }
		ND_EVENT_CATEGORY(EventCategoryKeyboard)
	protected:
		KeyEvent(int keycode) :
			m_keycode(keycode)
		{

		}
		int m_keycode;
	};

	class KeyPressedEvent :public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatcount): 
			KeyEvent(keycode), m_RepeatCount(repeatcount) {
		}
		int GetRepeatCount()const { return m_RepeatCount; }
		std::string ToString() const override{
			std::stringstream ss;
			ss << "KeyPressedEvent:" << m_keycode << "(" << m_RepeatCount << ")";
			return ss.str();
		}
		ND_EVENT_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};

	class KeyReleasedEvent :public KeyEvent {
	public:
		KeyReleasedEvent(int keycode): 
			KeyEvent(keycode){
		}
		std::string ToString() const override{
			std::stringstream ss;
			ss << "KeyReleasedEvent:" << m_keycode;
			return ss.str();
		}
		ND_EVENT_TYPE(keyReleased)
	};
}
