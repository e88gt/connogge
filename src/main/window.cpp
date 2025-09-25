#include "window.hpp"

void window_init(Window_T *self)
{
	if(!glfwInit())
	{
	}
	
	self->window = glfwCreateWindow(self->width, self->height, "Connogge", nullptr, nullptr);
}
