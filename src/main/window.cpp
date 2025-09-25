#include "window.hpp"

#include "utils.hpp"

static void _window_resize_callback(GLFWwindow *handle, const int width, const int height)
{
	Window_T *self = (Window_T*) glfwGetWindowUserPointer(handle);

	self->size.x = width;
	self->size.y = height;
}

void window_create(Window_T *self)
{
	if (!glfwInit())
	{
		ERROR("Failed to initialize window");
	}

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

	self->size.x = 1280;
	self->size.y = 720;
	self->handle = glfwCreateWindow(self->size.x, self->size.y, "Connogge", nullptr, nullptr);

	if (!self->handle)
	{
		ERROR("Failed to create window");
	}
	
	glfwSetWindowUserPointer(self->handle, (void*) self);
	glfwSetFramebufferSizeCallback(self->handle, _window_resize_callback);
	glfwMakeContextCurrent(self->handle);
}

void window_poll_events(const Window_T *)
{
	glfwPollEvents();
}

void window_swap_buffers(const Window_T *self)
{
	glfwSwapBuffers(self->handle);
}

void window_destroy(const Window_T *self)
{
	glfwDestroyWindow(self->handle);
	glfwTerminate();
}

bool window_should_close(const Window_T *self)
{
	return glfwWindowShouldClose(self->handle);
}

const glm::ivec2 &window_get_size(const Window_T *self)
{
	return self->size;
}
