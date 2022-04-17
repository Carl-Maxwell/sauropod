#pragma once

#include "Core.h"

#include "Events/Event.h"

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