#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "engine/utils/types.hpp"

class Camera
{
protected:
	Camera();

public:
	virtual ~Camera();

	[[nodiscard]] virtual Matrix4f GetViewMatrix() const = 0;

	[[nodiscard]] virtual Matrix4f GetProjection(const Vector2f &size) const = 0;
};

#endif //CAMERA_HPP
