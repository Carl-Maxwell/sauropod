#pragma once

#include "Core.h"

namespace Sauropod {

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