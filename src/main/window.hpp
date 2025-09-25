#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

typedef struct _window
{
	GLFWwindow *handle;
	glm::ivec2 size;
}
Window_T;

void window_create(Window_T *self);

void window_poll_events(const Window_T *self);

void window_swap_buffers(const Window_T *self);

void window_destroy(const Window_T *self);

bool window_should_close(const Window_T *self);

const glm::ivec2 &window_get_size(const Window_T *self);

#endif // _WINDOW_HPP
