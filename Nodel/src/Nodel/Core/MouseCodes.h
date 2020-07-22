#pragma once

namespace Nodel
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0                = 0,
		Button1                = 1,
		Button2                = 2,
		Button3                = 3,
		Button4                = 4,
		Button5                = 5,
		Button6                = 6,
		Button7                = 7,

		ButtonLast             = Button7,
		ButtonLeft             = Button0,
		ButtonRight            = Button1,
		ButtonMiddle           = Button2
	} Mouse;
	
	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define ND_MOUSE_BUTTON_0      ::Nodel::Mouse::Button0
#define ND_MOUSE_BUTTON_1      ::Nodel::Mouse::Button1
#define ND_MOUSE_BUTTON_2      ::Nodel::Mouse::Button2
#define ND_MOUSE_BUTTON_3      ::Nodel::Mouse::Button3
#define ND_MOUSE_BUTTON_4      ::Nodel::Mouse::Button4
#define ND_MOUSE_BUTTON_5      ::Nodel::Mouse::Button5
#define ND_MOUSE_BUTTON_6      ::Nodel::Mouse::Button6
#define ND_MOUSE_BUTTON_7      ::Nodel::Mouse::Button7
#define ND_MOUSE_BUTTON_LAST   ::Nodel::Mouse::ButtonLast
#define ND_MOUSE_BUTTON_LEFT   ::Nodel::Mouse::ButtonLeft
#define ND_MOUSE_BUTTON_RIGHT  ::Nodel::Mouse::ButtonRight
#define ND_MOUSE_BUTTON_MIDDLE ::Nodel::Mouse::ButtonMiddle
