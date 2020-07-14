#pragma once
#include "Nodel/Events/Event.h"

namespace Nodel {
	class Layer {
	public:
		Layer(const char* name = "default layer");
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnRender() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& e) {}

		inline const char* GetName() const { return m_Name; }
	protected:
		const char* m_Name;
	};
}
