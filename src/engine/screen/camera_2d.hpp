#ifndef CAMERA_2_D_HPP
#define CAMERA_2_D_HPP

#include "camera.hpp"

class Camera2D final : public Camera
{
public:
	Camera2D();

	~Camera2D() override;

	Vector2f &Position();

	float &Rotation();

	[[nodiscard]] Matrix4f GetViewMatrix() const override;

	[[nodiscard]] Matrix4f GetProjection(const Vector2f &size) const override;

private:
	float m_z_near, m_z_far;
	float m_rotation;
	Vector2f m_position;
};

#endif //CAMERA_2_D_HPP
