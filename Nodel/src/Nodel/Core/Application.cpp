#include "Application.h"
namespace Nodel {

	Application* Application::s_Instance = nullptr;

	Application::Application(const char* name /*= "Nodel App"*/):
		m_Running(true)
	{
		s_Instance = this;
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{

		}
	}


}