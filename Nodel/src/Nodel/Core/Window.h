#pragma once
#include "Nodel/Events/Event.h"

namespace Nodel {
	struct WindowProp {
		std::string Title;
		unsigned int Width, Height;
		WindowProp(const std::string& title = "Nodel Window", unsigned int width = 1280, unsigned int height = 720) :
			Title(title), Width(width), Height(height) {

		}
	};

	class Window {

	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool vsync) = 0;
		virtual bool GetVSync() const = 0;

		virtual void OnUpdate() = 0;

		virtual void SetEventCallback(const EventCallbackFn& fn) = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProp& prop = WindowProp());

	};
}
