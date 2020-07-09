#include "Nodel.h"

class SandBoxApp : public Nodel::Application {
public:
	SandBoxApp() {

	}
	~SandBoxApp() {

	}
};

Nodel::Application* Nodel::CreateApplication() {
	return new SandBoxApp();
}
