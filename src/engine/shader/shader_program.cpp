#include "shader_program.hpp"

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

GLuint ShaderProgram::GetHandle() const
{
	return m_handle;
}

ShaderProgram::operator GLuint() const
{
	return m_handle;
}
