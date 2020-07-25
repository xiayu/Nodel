#include "Nodel.h"

#include "Nodel/Core/EntryPoint.h"

#include "SandBox2D.h"

class SandBoxApp : public Nodel::Application {
public:
	SandBoxApp() {
		PushLayer(new SandBox2D());
	}
	~SandBoxApp() {

	}
};

Nodel::Application* Nodel::CreateApplication() {
	return new SandBoxApp();
}
