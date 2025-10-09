#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include "types.hpp"

class Transformation
{
protected:
	explicit Transformation();

public:
	virtual ~Transformation();

	[[nodiscard]] virtual Matrix4f GetTransformation() const = 0;
};

#endif //TRANSFORMATION_HPP
