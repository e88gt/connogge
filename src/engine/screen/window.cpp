#include "window.hpp"

namespace
{
	bool init = false;
	unsigned int windows_counter = 0;

	void init_window()
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

	void terminate_window()
	{
		if (!init)
		{
			return;
		}

		glfwTerminate();
		glfwSetErrorCallback(nullptr);

		init = false;
	}

	void size_callback(GLFWwindow *window, int width, int height)
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
		::init_window();
	}

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	m_handle = glfwCreateWindow(m_size.x, m_size.y, title.c_str(), nullptr, nullptr);

	if (!m_handle)
	{
		throw RuntimeError{ "Failed to create window" };
	}

	::windows_counter++;

	const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	const int x = (vidmode->width - m_size.x) / 2;
	const int y = (vidmode->height - m_size.y) / 2;
	glfwSetWindowPos(m_handle, x, y);

	glfwSetWindowUserPointer(m_handle, this);
	glfwSetFramebufferSizeCallback(m_handle, ::size_callback);

	glfwShowWindow(m_handle);
	MakeCurrent();
	glfwSwapInterval(1);
}

Window::~Window()
{
	glfwSetFramebufferSizeCallback(m_handle, nullptr);

	glfwDestroyWindow(m_handle);

	::windows_counter--;

	if (::windows_counter == 0)
	{
		::terminate_window();
	}
}

void Window::MakeCurrent() const
{
	glfwMakeContextCurrent(m_handle);
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

const Vector2i &Window::GetSize() const
{
	return m_size;
}
