#include "camera_3d.hpp"

#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

Camera3D::Camera3D()
	: m_fov{ 120.0f }, m_z_near{ 0.01f }, m_z_far{ 1000.0f }, m_position{}, m_rotation{}
{
}

Camera3D::~Camera3D() = default;

Vector3f &Camera3D::Position()
{
	return m_position;
}

Vector3f &Camera3D::Rotation()
{
	return m_rotation;
}

Matrix4f Camera3D::GetProjection(const Vector2f &size)
{
	Matrix4f m{ 1.0f };
	m = glm::perspective(glm::radians(m_fov), size.x / size.y, m_z_near, m_z_far);
	return m;
}

Matrix4f Camera3D::GetViewMatrix()
{
	Matrix4f m{ 1.0f };
	m = glm::rotate(m, glm::radians(-m_rotation.z), { 0.0f, 0.0f, 1.0f });
	m = glm::rotate(m, glm::radians(-m_rotation.y), { 0.0f, 1.0f, 0.0f });
	m = glm::rotate(m, glm::radians(-m_rotation.x), { 1.0f, 0.0f, 0.0f });
	m = glm::translate(m, -m_position);
	return m;
}
