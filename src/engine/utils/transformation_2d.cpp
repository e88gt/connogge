#include "transformation_2d.hpp"

#include "glm/ext/matrix_transform.hpp"

Transformation2D::Transformation2D(const float scale)
	: Transformation{}, m_position{}, m_scale{ scale }, m_rotation{}
{
}

Transformation2D::~Transformation2D() = default;

Vector2f &Transformation2D::Position()
{
	return m_position;
}

Vector2f &Transformation2D::Scale()
{
	return m_scale;
}

float &Transformation2D::Rotation()
{
	return m_rotation;
}

Matrix4f Transformation2D::GetTransformation() const
{
	Matrix4f m{ 1.0f };
	m = glm::translate(m, { m_position, 1.0f });
	m = glm::rotate(m, glm::radians(m_rotation), { 0.0f, 0.0f, 1.0f });
	m = glm::scale(m, { m_scale, 1.0f });
	return m;
}
