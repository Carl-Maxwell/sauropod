#include "application.h"

#include <stdio.h>

namespace sauropod {

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