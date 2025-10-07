#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP

#include <glad/glad.h>

#include "shader.hpp"

class ShaderProgram
{
public:
	explicit ShaderProgram();

	~ShaderProgram();

	void AttachShader(const Shader &shader) const;

	void Link() const;

	void Use() const;

	[[nodiscard]] GLuint GetHandle() const;

	[[nodiscard]] operator GLuint() const;

private:
	const GLuint m_handle;
};

#endif //SHADER_PROGRAM_HPP
