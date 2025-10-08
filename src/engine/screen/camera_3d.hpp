#ifndef CAMERA_3_D_HPP
#define CAMERA_3_D_HPP

#include "camera.hpp"

class Camera3D : public Camera
{
public:
	Camera3D();

	~Camera3D() override;

	Vector3f &Position();

	Vector3f &Rotation();

	[[nodiscard]] Matrix4f GetViewMatrix() override;

	[[nodiscard]] Matrix4f GetProjection(const Vector2f &size) override;

private:
	float m_fov, m_z_near, m_z_far;
	Vector3f m_position, m_rotation;
};

#endif //CAMERA_3_D_HPP
