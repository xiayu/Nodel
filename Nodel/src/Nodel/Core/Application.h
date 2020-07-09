#pragma once
int main(int argc, char** argv);

namespace Nodel {
	class Application {
	public:
		Application(const char* name = "Nodel App");
		virtual ~Application();
		Application& GetInstance() { return *s_Instance; }

	private:
		void Run();
	private:
		bool m_Running;
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	Nodel::Application* CreateApplication();
}

