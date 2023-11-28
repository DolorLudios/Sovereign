#pragma once

#include "Core.h";

namespace Sovereign {
	class SVG_API Application {
	public:
		Application() {


		}
		virtual ~Application() {



		}
		void Run();

	};


	Application* CreateApplication();
}

