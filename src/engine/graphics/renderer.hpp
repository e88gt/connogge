#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "engine/mesh/mesh.hpp"
#include "engine/utils/types.hpp"

class Renderer
{
public:
	explicit Renderer();

	~Renderer();

	void Viewport(const Vector2i &pos, const Vector2i &size) const;

	void ClearColor(const Color3f &color) const;

	void ClearBuffer() const;

	void Render(const Mesh &mesh) const;
};

#endif //RENDERER_HPP
