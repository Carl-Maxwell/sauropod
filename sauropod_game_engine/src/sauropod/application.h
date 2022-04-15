#pragma once

#include "core.h"

namespace sauropod {

	class SAUROPOD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}