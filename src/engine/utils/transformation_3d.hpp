#ifndef TRANSFORMATION_3D_HPP
#define TRANSFORMATION_3D_HPP

#include "transformation.hpp"

class Transformation3D final : public Transformation
{
public:
	explicit Transformation3D();

	~Transformation3D() override;

	[[nodiscard]] Matrix4f GetTransformation() override;

	Vector3f &Position();

	Vector3f &Rotation();

	Vector3f &Scale();

private:
	Vector3f m_position;
	Vector3f m_rotation;
	Vector3f m_scale;
};

#endif //TRANSFORMATION_3D_HPP
