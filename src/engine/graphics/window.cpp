#include "window.hpp"

namespace
{
	bool init = false;
	unsigned int windows_counter = 0;

	void InitWindow()
	{
		if (init)
		{
			return;
		}

		glfwSetErrorCallback([](int code, const char *description)
		{
			throw RuntimeError{ description };
		});

		init = glfwInit();

		if (!init)
		{
			throw RuntimeError{ "Failed to initialize window" };
		}
	}

	void TerminateWindow()
	{
		if (!init)
		{
			return;
		}

		glfwTerminate();
		glfwSetErrorCallback(nullptr);

		init = false;
	}

	void SizeCallback(GLFWwindow *window, int width, int height)
	{
		Window *self = static_cast<Window*>(glfwGetWindowUserPointer(window));
		self->Size() = { width, height };
	}
}

Window::Window(const String &title)
	: m_size{ 1280, 720 }
{
	if (!::init)
	{
		::InitWindow();
	}

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	m_handle = glfwCreateWindow(m_size.x, m_size.y, title.c_str(), nullptr, nullptr);

	windows_counter++;

	glfwSetWindowUserPointer(m_handle, this);
	glfwSetFramebufferSizeCallback(m_handle, ::SizeCallback);

	glfwShowWindow(m_handle);
	glfwMakeContextCurrent(m_handle);
	glfwSwapInterval(1);
}

Window::~Window()
{
	glfwSetFramebufferSizeCallback(m_handle, nullptr);

	glfwDestroyWindow(m_handle);

	windows_counter--;

	if (windows_counter == 0)
	{
		TerminateWindow();
	}
}

void Window::PollEvents() const
{
	glfwPollEvents();
}

void Window::SwapBuffers() const
{
	glfwSwapBuffers(m_handle);
}

bool Window::ShouldClose() const
{
	return glfwWindowShouldClose(m_handle);
}

Vector2i &Window::Size()
{
	return m_size;
}
