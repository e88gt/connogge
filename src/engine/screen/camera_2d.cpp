#include "camera_2d.hpp"

#include <glm/gtc/matrix_transform.hpp>

Camera2D::Camera2D()
	: Camera{}, m_z_near{ -10.0f }, m_z_far{ 10.0f }, m_rotation{}, m_position{}
{
}

Camera2D::~Camera2D() = default;

Matrix4f Camera2D::GetViewMatrix() const
{
	Matrix4f m{ 1.0f };
	m = glm::rotate(m, glm::radians(m_rotation), { 0.0f, 0.0f, 1.0f });
	m = glm::translate(m, { -m_position, 1.0f });
	return m;
}

Matrix4f Camera2D::GetProjection(const Vector2f &size) const
{
	Matrix4f m{ 1.0f };
	m = glm::ortho(0.0f, size.x, size.y, 0.0f, m_z_near, m_z_far);
	return m;
}
