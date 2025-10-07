#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include <glad/glad.h>

#include "vertex_buffer.hpp"
#include "element_buffer.hpp"

class VertexArray
{
public:
	explicit VertexArray();

	~VertexArray();

	void Bind() const;

	void SetVertexBuffer(const VertexBuffer &vb) const;

	void SetElementBuffer(const ElementBuffer &eb) const;

	void AddAttribute(GLuint location, GLint size) const;

	[[nodiscard]] GLuint GetHandle() const;

	[[nodiscard]] operator GLuint() const;

private:
	const GLuint m_handle;
};

#endif //VERTEX_ARRAY_HPP
