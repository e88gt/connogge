#ifndef MESH_HPP
#define MESH_HPP

#include "engine/graphics/vertex_array.hpp"

class Mesh
{
public:
	explicit Mesh(const List<Vertex> &vertices, const List<GLuint> &indices);

	~Mesh();

	[[nodiscard]] GLsizei GetSize() const;

	[[nodiscard]] const VertexArray &GetVertexArray() const;

private:
	const GLsizei m_size;
	const VertexArray m_vertex_array;
	const VertexBuffer m_vertex_buffer;
	const ElementBuffer m_element_buffer;
};

#endif //MESH_HPP
