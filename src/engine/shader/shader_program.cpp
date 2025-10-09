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

void ShaderProgram::SetUniformBool(const GLint location, const bool value) const
{
	glProgramUniform1i(m_handle, location, value);
}

void ShaderProgram::SetUniformInt(const GLint location, const int value) const
{
	glProgramUniform1i(m_handle, location, value);
}

void ShaderProgram::SetUniformFloat(const GLint location, const float value) const
{
	glProgramUniform1f(m_handle, location, value);
}

void ShaderProgram::SetUniformVector3f(const GLint location, const Vector3f &value) const
{
	glProgramUniform3f(m_handle, location, value.x, value.y, value.z);
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
