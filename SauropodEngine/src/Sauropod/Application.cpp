#include "Application.h"

#include <stdio.h>

namespace Sauropod {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		printf("Hello world!\n");
		while (true);
	}

}