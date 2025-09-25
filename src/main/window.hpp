#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

typedef struct _window
{
	GLFWwindow *window;
	int width, height;
}
Window_T;

void window_init(Window_T *self);

#endif // _WINDOW_HPP
