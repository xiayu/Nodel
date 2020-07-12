#include "ndpch.h"
#include "Nodel/Core/LayerStack.h"
namespace Nodel {

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers) {
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		++m_LayerInsertIndex;
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto _begin = m_Layers.begin();
		auto _end = m_Layers.begin() + m_LayerInsertIndex;
		auto iter = std::find(_begin, _end, layer);
		if (iter != _end) {
			layer->OnDetach();
			m_Layers.erase(iter);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto _begin = m_Layers.begin() + m_LayerInsertIndex;
		auto _end = m_Layers.end();

		auto iter = std::find(_begin, _end, overlay);
		if (iter != _end) {
			overlay->OnDetach();
			m_Layers.erase(iter);
		}
	}

}