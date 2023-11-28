#pragma once

#ifdef SVG_PLATFORM_WINDOWS

extern Sovereign::Application* Sovereign::CreateApplication();

int main(int argc, char **argv) {
	printf("Sovereign is ready to conquer");
	auto app = Sovereign::CreateApplication();
	app->Run();
	delete app;
}

#endif
