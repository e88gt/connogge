#include "shader_program.hpp"

#include <algorithm>

#include "glm/gtc/type_ptr.hpp"

ShaderProgram::ShaderProgram()
	: m_handle{ glCreateProgram() }
{
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(m_handle);
}

void ShaderProgram::AttachShader(const Shader &shader) const
{
	glAttachShader(m_handle, shader);
}

void ShaderProgram::Link() const
{
	glLinkProgram(m_handle);
}

void ShaderProgram::Use() const
{
	glUseProgram(m_handle);
}

void ShaderProgram::SetUniformMatrix4f(const GLint location, const Matrix4f &matrix) const
{
	glProgramUniformMatrix4fv(m_handle, location, 1, GL_FALSE, glm::value_ptr(matrix));
}

GLuint ShaderProgram::GetHandle() const
{
	return m_handle;
}

ShaderProgram::operator GLuint() const
{
	return m_handle;
}
