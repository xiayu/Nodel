#include "ndpch.h"
#include "Nodel/Core/Window.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Nodel {
	Window* Window::Create(const WindowProp& prop)
	{
#ifdef ND_PLATFORM_WINDOWS
		return new WindowsWindow(prop);
#endif
		return nullptr;
	}
}
