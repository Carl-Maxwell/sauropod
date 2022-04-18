#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Window.h"

namespace Sauropod {

	class SAUROPOD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
