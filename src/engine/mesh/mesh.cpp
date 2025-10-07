#include "mesh.hpp"

Mesh::Mesh(const List<Vertex> &vertices, const List<GLuint> &indices)
	: m_size{ static_cast<GLsizei>(indices.size()) }, m_vertex_array{}, m_vertex_buffer{}, m_element_buffer{}
{
	m_vertex_buffer.StoreData(vertices);
	m_element_buffer.StoreData(indices);

	m_vertex_array.SetVertexBuffer(m_vertex_buffer);
	m_vertex_array.SetElementBuffer(m_element_buffer);

	m_vertex_array.AddAttribute(0, 3);
	m_vertex_array.AddAttribute(1, 2);
}

Mesh::~Mesh() = default;

GLsizei Mesh::GetSize() const
{
	return m_size;
}

const VertexArray &Mesh::GetVertexArray() const
{
	return m_vertex_array;
}
