#include "Engine.hpp"

#include "Time.hpp"

Engine::Engine()
	: running{ false }, window{ "Connogge" }, renderer{}
{
	start();
}

Engine::~Engine() = default;

void Engine::run()
{
	double lastTime = systemNanoTime();
	while(running)
	{
		input();
		
		if(shouldClose())
		{
			stop();
		}
		
		const double currentTime = systemNanoTime();
		const double deltaTime = (currentTime - lastTime) / NS_PER_SEC;
		lastTime = currentTime;
		
		update(deltaTime);
		render();
	}
}

void Engine::input()
{
	window.pollEvents();
}

void Engine::update(double delta)
{
	renderer.viewport(window.getSize().x, window.getSize().y);
	renderer.clearColor(0.65f, 0.65f, 1.0f);
}

void Engine::render()
{
	renderer.clear();
	window.swapBuffers();
}

bool Engine::shouldClose() const
{
	return window.shouldClose();
}

void Engine::start()
{
	if(running)
	{
		return;
	}
	running = true;
}

void Engine::stop()
{
	if(!running)
	{
		return;
	}
	running = false;
}
