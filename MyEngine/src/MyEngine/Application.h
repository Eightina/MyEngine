#pragma once

#include "Core.h"
#include "MyEngine/Events/Event.h"

namespace MyEngine {

	class MYENGINE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defined in CLIENT
	Application* CreateApplication();

}

