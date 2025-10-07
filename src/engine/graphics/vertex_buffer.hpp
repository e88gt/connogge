#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include <glad/glad.h>

#include "engine/graphics/vertex.hpp"
#include "engine/utils/types.hpp"

class VertexBuffer
{
public:
	explicit VertexBuffer();

	~VertexBuffer();

	void Bind() const;

	void Data(const List<Vertex> &vertices) const;

	[[nodiscard]] GLuint GetHandle() const;

	[[nodiscard]] operator GLuint() const;

private:
	const GLuint m_handle;
};

#endif //VERTEX_BUFFER_HPP
