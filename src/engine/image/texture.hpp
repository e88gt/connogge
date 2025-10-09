#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <stb_image.h>
#include <glad/glad.h>

#include "image_data.hpp"
#include "engine/utils/types.hpp"

class Texture
{
public:
	explicit Texture(const String &path, bool flip);

	explicit Texture(const ImageData &image);

	explicit Texture(const stbi_uc *pixels, const Vector2i &size);

	~Texture();

	void Bind() const;

	[[nodiscard]] GLuint GetHandle() const;

	[[nodiscard]] operator GLuint() const;

private:
	const GLuint m_handle;
};

#endif //TEXTURE_HPP
