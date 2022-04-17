#include "hzpch.h"

#include <stdio.h>

#include "Sauropod/Events/ApplicationEvent.h"
#include "Sauropod/Log.h"

#include "Application.h"

namespace Sauropod {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HZ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HZ_TRACE(e);
		}

		printf("Hello world!\n");
		while (true);
	}

}