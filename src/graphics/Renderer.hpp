#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glad/glad.h>

class Renderer
{
public:
	explicit Renderer();
	
	~Renderer();
	
	void viewport(GLsizei width, GLsizei height) const;
	
	void clearColor(GLfloat r, GLfloat g, GLfloat b) const;
	
	void clear() const;
};

#endif // RENDERER_HPP
