#pragma once

#ifdef SVG_PLATFORM_WINDOWS

extern Sovereign::Application* Sovereign::CreateApplication();

int main(int argc, char **argv) {

	Sovereign::Log::Init();
	SVG_CORE_WARN("Initialized log");
	SVG_INFO("Hello");


	auto app = Sovereign::CreateApplication();
	app->Run();
	delete app;
}

#endif
