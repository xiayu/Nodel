#pragma once
#include "Application.h"
#include "Nodel/Core/Log.h"

extern Nodel::Application* Nodel::CreateApplication();

int main(int argc, char** argv) {
	Nodel::Log::Init();
	auto app = Nodel::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
