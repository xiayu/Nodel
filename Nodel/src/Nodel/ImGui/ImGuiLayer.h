#pragma once
#include "Nodel/Core/Layer.h"

namespace Nodel {

	class ImGuiLayer:public Layer
	{
	public:
		ImGuiLayer();

		virtual void OnAttach() override;


		virtual void OnDetach() override;

		virtual void OnRender() override;

		virtual void OnEvent(Event& e) override;

		void Begin();

		void End();

	};
}

