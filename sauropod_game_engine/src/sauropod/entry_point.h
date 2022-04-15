#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern sauropod::Application* sauropod::CreateApplication();

int main(int argc, char** argv)
{
	auto app = sauropod::CreateApplication();
	app->Run();
	delete app;
}

#endif