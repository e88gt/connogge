#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "system/events.hpp"
#include "screen/window.hpp"
#include "graphics/renderer.hpp"
#include "core/core.hpp"

class Engine
{
public:
	Engine();

	~Engine();

	void Run();

private:
	void OnEvent();

	void OnUpdate(double delta);

	void OnRender();

	void Start();

	void Stop();

private:
	bool m_running;
	Core m_core;
	const Window m_window;
	const Renderer m_renderer;
};

#endif //ENGINE_HPP
