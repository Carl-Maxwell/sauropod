#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern sauropod::Application* sauropod::CreateApplication();

int main(int argc, char** argv)
{
	sauropod::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	auto a = 5;
	HZ_INFO("Hello world! Var={0}", a);

	auto app = sauropod::CreateApplication();
	app->Run();
	delete app;
}

#endif