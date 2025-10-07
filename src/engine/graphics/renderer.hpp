#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "vertex_array.hpp"
#include "engine/utils/types.hpp"

class Renderer
{
public:
	explicit Renderer();

	~Renderer();

	void Viewport(const Vector2i &pos, const Vector2i &size) const;

	void ClearColor(const Color3f &color) const;

	void ClearBuffer() const;

	void Render(const VertexArray &va, const List<GLuint> &indices) const;
};

#endif //RENDERER_HPP
