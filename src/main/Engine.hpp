
#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "../graphics/Window.hpp"
#include "../graphics/Renderer.hpp"

#include "Connogge.hpp"

class Engine
{
public:
	explicit Engine();
	
	~Engine();
	
	void run();
	
private:
	void input();
	
	void update(double delta);
	
	void render();
	
	[[nodiscard]] bool shouldClose() const;
	
	void start();
	
	void stop();
	
private:
	bool running;
	const Window window;
	const Renderer renderer;
};

#endif // ENGINE_HPP
