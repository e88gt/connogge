#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "system/events.hpp"
#include "screen/window.hpp"
#include "graphics/renderer.hpp"

class Engine
{
public:
	Engine();

	~Engine();

	void Run();

private:
	void OnEvent(const Events &event);

	void OnUpdate(double delta);

	void OnRender(const Renderer &renderer);

private:
	const Window window;
};

#endif //ENGINE_HPP
