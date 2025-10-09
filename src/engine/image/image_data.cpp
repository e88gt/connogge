#include "image_data.hpp"

ImageData::ImageData(const String &title, const bool flip)
	: m_pixels{}, m_size{}
{
	int channels;

	stbi_set_flip_vertically_on_load(flip);

	m_pixels = stbi_load(title.c_str(), &m_size.x, &m_size.y, &channels, STBI_rgb_alpha);

	if (!m_pixels)
	{
		throw RuntimeError{ stbi_failure_reason() };
	}
}

ImageData::~ImageData()
{
	stbi_image_free(m_pixels);
}

const Vector2i &ImageData::GetSize() const
{
	return m_size;
}

const stbi_uc *ImageData::GetPixels() const
{
	return m_pixels;
}
