#pragma once

namespace Nodel
{
	enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	};

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define ND_KEY_SPACE           ::Nodel::KeyCode::Space
#define ND_KEY_APOSTROPHE      ::Nodel::KeyCode::Apostrophe    /* ' */
#define ND_KEY_COMMA           ::Nodel::KeyCode::Comma         /* , */
#define ND_KEY_MINUS           ::Nodel::KeyCode::Minus         /* - */
#define ND_KEY_PERIOD          ::Nodel::KeyCode::Period        /* . */
#define ND_KEY_SLASH           ::Nodel::KeyCode::Slash         /* / */
#define ND_KEY_0               ::Nodel::KeyCode::D0
#define ND_KEY_1               ::Nodel::KeyCode::D1
#define ND_KEY_2               ::Nodel::KeyCode::D2
#define ND_KEY_3               ::Nodel::KeyCode::D3
#define ND_KEY_4               ::Nodel::KeyCode::D4
#define ND_KEY_5               ::Nodel::KeyCode::D5
#define ND_KEY_6               ::Nodel::KeyCode::D6
#define ND_KEY_7               ::Nodel::KeyCode::D7
#define ND_KEY_8               ::Nodel::KeyCode::D8
#define ND_KEY_9               ::Nodel::KeyCode::D9
#define ND_KEY_SEMICOLON       ::Nodel::KeyCode::Semicolon     /* ; */
#define ND_KEY_EQUAL           ::Nodel::KeyCode::Equal         /* = */
#define ND_KEY_A               ::Nodel::KeyCode::A
#define ND_KEY_B               ::Nodel::KeyCode::B
#define ND_KEY_C               ::Nodel::KeyCode::C
#define ND_KEY_D               ::Nodel::KeyCode::D
#define ND_KEY_E               ::Nodel::KeyCode::E
#define ND_KEY_F               ::Nodel::KeyCode::F
#define ND_KEY_G               ::Nodel::KeyCode::G
#define ND_KEY_H               ::Nodel::KeyCode::H
#define ND_KEY_I               ::Nodel::KeyCode::I
#define ND_KEY_J               ::Nodel::KeyCode::J
#define ND_KEY_K               ::Nodel::KeyCode::K
#define ND_KEY_L               ::Nodel::KeyCode::L
#define ND_KEY_M               ::Nodel::KeyCode::M
#define ND_KEY_N               ::Nodel::KeyCode::N
#define ND_KEY_O               ::Nodel::KeyCode::O
#define ND_KEY_P               ::Nodel::KeyCode::P
#define ND_KEY_Q               ::Nodel::KeyCode::Q
#define ND_KEY_R               ::Nodel::KeyCode::R
#define ND_KEY_S               ::Nodel::KeyCode::S
#define ND_KEY_T               ::Nodel::KeyCode::T
#define ND_KEY_U               ::Nodel::KeyCode::U
#define ND_KEY_V               ::Nodel::KeyCode::V
#define ND_KEY_W               ::Nodel::KeyCode::W
#define ND_KEY_X               ::Nodel::KeyCode::X
#define ND_KEY_Y               ::Nodel::KeyCode::Y
#define ND_KEY_Z               ::Nodel::KeyCode::Z
#define ND_KEY_LEFT_BRACKET    ::Nodel::KeyCode::LeftBracket   /* [ */
#define ND_KEY_BACKSLASH       ::Nodel::KeyCode::Backslash     /* \ */
#define ND_KEY_RIGHT_BRACKET   ::Nodel::KeyCode::RightBracket  /* ] */
#define ND_KEY_GRAVE_ACCENT    ::Nodel::KeyCode::GraveAccent   /* ` */
#define ND_KEY_WORLD_1         ::Nodel::KeyCode::World1        /* non-US #1 */
#define ND_KEY_WORLD_2         ::Nodel::KeyCode::World2        /* non-US #2 */

/* Function keys */
#define ND_KEY_ESCAPE          ::Nodel::KeyCode::Escape
#define ND_KEY_ENTER           ::Nodel::KeyCode::Enter
#define ND_KEY_TAB             ::Nodel::KeyCode::Tab
#define ND_KEY_BACKSPACE       ::Nodel::KeyCode::Backspace
#define ND_KEY_INSERT          ::Nodel::KeyCode::Insert
#define ND_KEY_DELETE          ::Nodel::KeyCode::Delete
#define ND_KEY_RIGHT           ::Nodel::KeyCode::Right
#define ND_KEY_LEFT            ::Nodel::KeyCode::Left
#define ND_KEY_DOWN            ::Nodel::KeyCode::Down
#define ND_KEY_UP              ::Nodel::KeyCode::Up
#define ND_KEY_PAGE_UP         ::Nodel::KeyCode::PageUp
#define ND_KEY_PAGE_DOWN       ::Nodel::KeyCode::PageDown
#define ND_KEY_HOME            ::Nodel::KeyCode::Home
#define ND_KEY_END             ::Nodel::KeyCode::End
#define ND_KEY_CAPS_LOCK       ::Nodel::KeyCode::CapsLock
#define ND_KEY_SCROLL_LOCK     ::Nodel::KeyCode::ScrollLock
#define ND_KEY_NUM_LOCK        ::Nodel::KeyCode::NumLock
#define ND_KEY_PRINT_SCREEN    ::Nodel::KeyCode::PrintScreen
#define ND_KEY_PAUSE           ::Nodel::KeyCode::Pause
#define ND_KEY_F1              ::Nodel::KeyCode::F1
#define ND_KEY_F2              ::Nodel::KeyCode::F2
#define ND_KEY_F3              ::Nodel::KeyCode::F3
#define ND_KEY_F4              ::Nodel::KeyCode::F4
#define ND_KEY_F5              ::Nodel::KeyCode::F5
#define ND_KEY_F6              ::Nodel::KeyCode::F6
#define ND_KEY_F7              ::Nodel::KeyCode::F7
#define ND_KEY_F8              ::Nodel::KeyCode::F8
#define ND_KEY_F9              ::Nodel::KeyCode::F9
#define ND_KEY_F10             ::Nodel::KeyCode::F10
#define ND_KEY_F11             ::Nodel::KeyCode::F11
#define ND_KEY_F12             ::Nodel::KeyCode::F12
#define ND_KEY_F13             ::Nodel::KeyCode::F13
#define ND_KEY_F14             ::Nodel::KeyCode::F14
#define ND_KEY_F15             ::Nodel::KeyCode::F15
#define ND_KEY_F16             ::Nodel::KeyCode::F16
#define ND_KEY_F17             ::Nodel::KeyCode::F17
#define ND_KEY_F18             ::Nodel::KeyCode::F18
#define ND_KEY_F19             ::Nodel::KeyCode::F19
#define ND_KEY_F20             ::Nodel::KeyCode::F20
#define ND_KEY_F21             ::Nodel::KeyCode::F21
#define ND_KEY_F22             ::Nodel::KeyCode::F22
#define ND_KEY_F23             ::Nodel::KeyCode::F23
#define ND_KEY_F24             ::Nodel::KeyCode::F24
#define ND_KEY_F25             ::Nodel::KeyCode::F25

/* Keypad */
#define ND_KEY_KP_0            ::Nodel::KeyCode::KP0
#define ND_KEY_KP_1            ::Nodel::KeyCode::KP1
#define ND_KEY_KP_2            ::Nodel::KeyCode::KP2
#define ND_KEY_KP_3            ::Nodel::KeyCode::KP3
#define ND_KEY_KP_4            ::Nodel::KeyCode::KP4
#define ND_KEY_KP_5            ::Nodel::KeyCode::KP5
#define ND_KEY_KP_6            ::Nodel::KeyCode::KP6
#define ND_KEY_KP_7            ::Nodel::KeyCode::KP7
#define ND_KEY_KP_8            ::Nodel::KeyCode::KP8
#define ND_KEY_KP_9            ::Nodel::KeyCode::KP9
#define ND_KEY_KP_DECIMAL      ::Nodel::KeyCode::KPDecimal
#define ND_KEY_KP_DIVIDE       ::Nodel::KeyCode::KPDivide
#define ND_KEY_KP_MULTIPLY     ::Nodel::KeyCode::KPMultiply
#define ND_KEY_KP_SUBTRACT     ::Nodel::KeyCode::KPSubtract
#define ND_KEY_KP_ADD          ::Nodel::KeyCode::KPAdd
#define ND_KEY_KP_ENTER        ::Nodel::KeyCode::KPEnter
#define ND_KEY_KP_EQUAL        ::Nodel::KeyCode::KPEqual

#define ND_KEY_LEFT_SHIFT      ::Nodel::KeyCode::LeftShift
#define ND_KEY_LEFT_CONTROL    ::Nodel::KeyCode::LeftControl
#define ND_KEY_LEFT_ALT        ::Nodel::KeyCode::LeftAlt
#define ND_KEY_LEFT_SUPER      ::Nodel::KeyCode::LeftSuper
#define ND_KEY_RIGHT_SHIFT     ::Nodel::KeyCode::RightShift
#define ND_KEY_RIGHT_CONTROL   ::Nodel::KeyCode::RightControl
#define ND_KEY_RIGHT_ALT       ::Nodel::KeyCode::RightAlt
#define ND_KEY_RIGHT_SUPER     ::Nodel::KeyCode::RightSuper
#define ND_KEY_MENU            ::Nodel::KeyCode::Menu
