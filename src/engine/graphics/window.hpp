#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <GLFW/glfw3.h>

#include "engine/utils/types.hpp"

class Window
{
public:
	explicit Window(const String &title);

	~Window();

	void PollEvents() const;

	void SwapBuffers() const;

	[[nodiscard]] bool ShouldClose() const;

	Vector2i &Size();

private:
	GLFWwindow *m_handle;
	Vector2i m_size;
};

#endif // WINDOW_HPP
