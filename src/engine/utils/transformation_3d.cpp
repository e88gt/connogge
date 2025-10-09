#include "transformation_3d.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#include "types.hpp"

Transformation3D::Transformation3D()
	: m_position{}, m_rotation{}, m_scale{ 1.0f }
{
}

Transformation3D::~Transformation3D() = default;

Matrix4f Transformation3D::GetTransformation() const
{
	Matrix4f m{ 1.0f };
	m = glm::translate(m, m_position);
	m = glm::rotate(m, glm::radians(m_rotation.x), { 1.0f, 0.0f, 0.0f });
	m = glm::rotate(m, glm::radians(m_rotation.y), { 0.0f, 1.0f, 0.0f });
	m = glm::rotate(m, glm::radians(m_rotation.z), { 0.0f, 0.0f, 1.0f });
	m = glm::scale(m, m_scale);
	return m;
}

Vector3f &Transformation3D::Position()
{
	return m_position;
}

Vector3f &Transformation3D::Rotation()
{
	return m_rotation;
}

Vector3f &Transformation3D::Scale()
{
	return m_scale;
}
