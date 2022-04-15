#include <sauropod.h>

class Sandbox : public sauropod::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

sauropod::Application* sauropod::CreateApplication()
{
	return new Sandbox();
}