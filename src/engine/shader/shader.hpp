#ifndef SHADER_HPP
#define SHADER_HPP

#include "engine/utils/types.hpp"
#include "shader_type.hpp"

class Shader
{
public:
	explicit Shader(const ShaderType &type);

	~Shader();

	void SetSource(const String &source) const;

	void Compile() const;

	[[nodiscard]] GLuint GetHandle() const;

	[[nodiscard]] operator GLuint() const;

private:
	const GLuint m_handle;
};

#endif //SHADER_HPP
