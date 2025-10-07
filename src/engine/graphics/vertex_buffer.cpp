#include "vertex_buffer.hpp"

namespace
{
	[[nodiscard]] GLuint create_vertex_buffer()
	{
		GLuint vertex_buffer;
		glCreateBuffers(1, &vertex_buffer);
		return vertex_buffer;
	}
}

VertexBuffer::VertexBuffer()
	: m_handle{ ::create_vertex_buffer() }
{
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_handle);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_handle);
}

void VertexBuffer::StoreData(const List<Vertex> &vertices) const
{
	glNamedBufferData(m_handle, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

GLuint VertexBuffer::GetHandle() const
{
	return m_handle;
}

VertexBuffer::operator GLuint() const
{
	return m_handle;
}
