#include "window.hpp"

#include <iostream>
#include <stdexcept>

static void windowResizeCallback(GLFWwindow *window, int width, int height)
{
	Window *self = static_cast<Window*>(glfwGetWindowUserPointer(window));
	self->callbackSetSize(width, height);
}

Window::Window(const std::string &title)
	: size{ 1280, 720 }
{
	if(!glfwInit())
	{
		throw std::runtime_error{ "Failed to initialize window" };
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
	
	handle = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr);
	
	if(!handle)
	{
		throw std::runtime_error{ "Failed to create window" };
	}
	
	glfwSetWindowUserPointer(handle, this);
	glfwSetFramebufferSizeCallback(handle, windowResizeCallback);
	glfwMakeContextCurrent(handle);
}

Window::~Window()
{
	glfwSetFramebufferSizeCallback(handle, nullptr);
	glfwDestroyWindow(handle);
	glfwTerminate();
}

void Window::pollEvents() const
{
	glfwPollEvents();
}

void Window::swapBuffers() const
{
	glfwSwapBuffers(handle);
}

bool Window::shouldClose() const
{
	return glfwWindowShouldClose(handle);
}

const glm::ivec2 &Window::getSize() const
{
	return size;
}

void Window::callbackSetSize(const int width, const int height)
{
	size.x = width;
	size.y = height;
}
