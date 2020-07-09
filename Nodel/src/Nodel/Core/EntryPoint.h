#pragma once
#include "Application.h"

extern Nodel::Application* Nodel::CreateApplication();

int main(int argc, char** argv) {
	auto app = Nodel::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
