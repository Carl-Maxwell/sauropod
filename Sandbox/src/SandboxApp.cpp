#include <Sauropod.h>

class Sandbox : public Sauropod::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Sauropod::Application* Sauropod::CreateApplication()
{
	return new Sandbox();
}