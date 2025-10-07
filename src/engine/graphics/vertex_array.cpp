#include "vertex_array.hpp"

namespace
{
	GLuint create_vertex_array()
	{
		GLuint vertex_array;
		glCreateVertexArrays(1, &vertex_array);
		return vertex_array;
	}
}

VertexArray::VertexArray()
	: m_handle{ ::create_vertex_array() }
{
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_handle);
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_handle);
}

void VertexArray::SetVertexBuffer(const VertexBuffer &vb) const
{
	glVertexArrayVertexBuffer(m_handle, 0, vb, 0, sizeof(Vertex));
}

void VertexArray::SetElementBuffer(const ElementBuffer &eb) const
{
	glVertexArrayElementBuffer(m_handle, eb);
}

namespace
{
	GLuint va_last_attr_size = 0;
}

void VertexArray::AddAttribute(const GLuint location, const GLint size) const
{
	glEnableVertexArrayAttrib(m_handle, location);
	glVertexArrayAttribFormat(m_handle, location, size, GL_FLOAT, GL_FALSE, va_last_attr_size);
	va_last_attr_size = size * sizeof(GLfloat);
}

GLuint VertexArray::GetHandle() const
{
	return m_handle;
}

VertexArray::operator GLuint() const
{
	return m_handle;
}
