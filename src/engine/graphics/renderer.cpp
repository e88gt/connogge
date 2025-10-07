#include "renderer.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace
{
	void renderer_error_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
	{
		throw RuntimeError{ message };
	}
}

Renderer::Renderer()
{
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		throw RuntimeError{ "Failed to initialize renderer" };
	}

	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, nullptr, true);
	glDebugMessageCallback(::renderer_error_callback, nullptr);
}

Renderer::~Renderer() = default;

void Renderer::Viewport(const Vector2i &pos, const Vector2i &size) const
{
	glViewport(pos.x, pos.y, size.x, size.y);
}

void Renderer::ClearColor(const Color3f &color) const
{
	glClearColor(color.r, color.g, color.b, 1.0f);
}

void Renderer::ClearBuffer() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Renderer::Render(const VertexArray &va, const List<GLuint> &indices) const
{
	va.Bind();
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
}
