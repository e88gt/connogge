#include "shader.hpp"

Shader::Shader(const ShaderType &type)
	: m_handle{ glCreateShader(static_cast<GLenum>(type)) }
{
}

Shader::~Shader()
{
	glDeleteShader(m_handle);
}

void Shader::SetSource(const String &source) const
{
	const char *source_c_str = source.c_str();
	glShaderSource(m_handle, 1, &source_c_str, nullptr);
}

void Shader::Compile() const
{
	glCompileShader(m_handle);
}

GLuint Shader::GetHandle() const
{
	return m_handle;
}

Shader::operator GLuint() const
{
	return m_handle;
}
