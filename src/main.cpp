#include "engine/graphics/window.hpp"

int main()
{
	const Window window = Window{ "Test" };

	while (!window.ShouldClose())
	{
		window.PollEvents();
		window.SwapBuffers();
	}
}
