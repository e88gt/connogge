#ifndef IMAGE_DATA_HPP
#define IMAGE_DATA_HPP

#include "stb_image.h"
#include "engine/utils/types.hpp"

class ImageData
{
public:
	explicit ImageData(const String &title, bool flip);

	~ImageData();

	const Vector2i &GetSize() const;

	const stbi_uc *GetPixels() const;

private:
	stbi_uc *m_pixels;
	Vector2i m_size;
};

#endif //IMAGE_DATA_HPP
