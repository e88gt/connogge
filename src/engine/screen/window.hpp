#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "engine/utils/types.hpp"

class Window
{
public:
	explicit Window(const String &title);

	~Window();

	void MakeCurrent() const;

	void SwapBuffers() const;

	[[nodiscard]] bool ShouldClose() const;

	Vector2i &Size();

	[[nodiscard]] const Vector2i &GetSize() const;

private:
	GLFWwindow *m_handle;
	Vector2i m_size;
};

#endif // WINDOW_HPP
