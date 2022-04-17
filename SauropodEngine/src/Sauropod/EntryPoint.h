#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Sauropod::Application* Sauropod::CreateApplication();

int main(int argc, char** argv)
{
	Sauropod::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	auto a = 5;
	HZ_INFO("Hello world! Var={0}", a);

	auto app = Sauropod::CreateApplication();
	app->Run();
	delete app;
}

#endif