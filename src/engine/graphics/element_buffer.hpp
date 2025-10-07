#ifndef ELEMENT_BUFFER_HPP
#define ELEMENT_BUFFER_HPP

#include <glad/glad.h>

#include "engine/utils/types.hpp"

class ElementBuffer
{
public:
	explicit ElementBuffer();

	~ElementBuffer();

	void Bind() const;

	void StoreData(const List<GLuint> &indices) const;

	[[nodiscard]] GLuint GetHandle() const;

	[[nodiscard]] operator GLuint() const;

private:
	const GLuint m_handle;
};

#endif //ELEMENT_BUFFER_HPP
