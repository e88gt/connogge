#include "texture.hpp"

namespace
{
	[[nodiscard]] GLuint create_texture()
	{
		GLuint texture;
		glCreateTextures(GL_TEXTURE_2D, 1, &texture);
		return texture;
	}
}

Texture::Texture(const String &path, const bool flip)
	: Texture{ ImageData{ path, flip } }
{
}

Texture::Texture(const ImageData &image)
	: Texture{ image.GetPixels(), image.GetSize() }
{
}

Texture::Texture(const stbi_uc *pixels, const Vector2i &size)
	: m_handle{ ::create_texture() }
{
	glTextureStorage2D(m_handle, 1, GL_RGBA8, size.x, size.y);
	glTextureSubImage2D(m_handle, 0, 0, 0, size.x, size.y, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	glTextureParameteri(m_handle, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTextureParameteri(m_handle, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTextureParameteri(m_handle, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTextureParameteri(m_handle, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glGenerateTextureMipmap(m_handle);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_handle);
}

void Texture::Bind() const
{
	glBindTextureUnit(0, m_handle);
}

GLuint Texture::GetHandle() const
{
	return m_handle;
}

Texture::operator GLuint() const
{
	return m_handle;
}
