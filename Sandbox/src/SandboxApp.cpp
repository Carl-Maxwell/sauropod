#include <Sauropod.h>

class ExampleLayer : public Sauropod::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		// HZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Sauropod::Event& event) override
	{
		// HZ_TRACE("{0}", event);
	}

};

class Sandbox : public Sauropod::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Sauropod::ImguiLayer());
	}

	~Sandbox()
	{

	}

};

Sauropod::Application* Sauropod::CreateApplication()
{
	return new Sandbox();
}