#include "element_buffer.hpp"

namespace
{
	[[nodiscard]] GLuint create_element_buffer()
	{
		GLuint element_buffer;
		glCreateBuffers(1, &element_buffer);
		return element_buffer;
	}
}

ElementBuffer::ElementBuffer()
	: m_handle{ create_element_buffer() }
{
}

ElementBuffer::~ElementBuffer()
{
	glDeleteBuffers(1, &m_handle);
}

void ElementBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
}

void ElementBuffer::Data(const List<GLuint> &indices) const
{
	glNamedBufferData(m_handle, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

GLuint ElementBuffer::GetHandle() const
{
	return m_handle;
}

ElementBuffer::operator GLuint() const
{
	return m_handle;
}
