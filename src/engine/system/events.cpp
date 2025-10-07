#include "events.hpp"

#include <GLFW/glfw3.h>

void Events::PollAll()
{
	glfwPollEvents();
}
