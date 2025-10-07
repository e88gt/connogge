#include "engine.hpp"

#include "utils/time.hpp"

Engine::Engine()
	: m_running{ false }, m_core{}, m_window{ "connogge" }, m_renderer{}
{
}

Engine::~Engine() = default;

void Engine::Run()
{
	Start();

	double last_time = Time::Nano();
	while (m_running)
	{
		double current_time = Time::Nano();
		double delta_time = (current_time - last_time) / Time::NS_PER_SEC;
		last_time = current_time;

		OnEvent();
		OnUpdate(delta_time);
		OnRender();
	}
}

void Engine::OnEvent()
{
	Events::PollAll();

	if (m_window.ShouldClose())
	{
		Stop();
	}
}

void Engine::OnUpdate(double delta)
{
	m_renderer.Viewport({ 0, 0 }, m_window.GetSize());
	m_renderer.ClearColor({ 0.65f, 1.0f, 0.65f });
}

void Engine::OnRender()
{
	m_renderer.ClearBuffer();
	m_window.SwapBuffers();
}

void Engine::Start()
{
	m_running = true;
}

void Engine::Stop()
{
	m_running = false;
}
