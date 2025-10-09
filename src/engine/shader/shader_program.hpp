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

	void SetUniformBool(GLint location, bool value) const;

	void SetUniformInt(GLint location, int value) const;

	void SetUniformFloat(GLint location, float value) const;

	void SetUniformVector3f(GLint location, const Vector3f &value) const;

	void SetUniformMatrix4f(GLint location, const Matrix4f &matrix) const;

	[[nodiscard]] GLuint GetHandle() const;

	[[nodiscard]] operator GLuint() const;

private:
	const GLuint m_handle;
};

#endif //SHADER_PROGRAM_HPP
