#include "Renderer.hpp"

#include <stdexcept>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Renderer::Renderer()
{
	if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		throw std::runtime_error{ "Failed to initialize renderer" };
	}
}

Renderer::~Renderer() = default;

void Renderer::viewport(const GLsizei width, const GLsizei height) const
{
	glViewport(0, 0, width, height);
}

void Renderer::clearColor(const GLfloat r, const GLfloat g, const GLfloat b) const
{
	glClearColor(r, g, b, 1.0f);
}

void Renderer::clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}
