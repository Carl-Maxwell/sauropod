#pragma once

#include "Core.h"

#include "Window.h"
#include "Sauropod/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Sauropod {

	class SAUROPOD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void Run();

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; };
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
