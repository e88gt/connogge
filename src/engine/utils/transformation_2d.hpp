#ifndef TRANSFORMATION_2_D_HPP
#define TRANSFORMATION_2_D_HPP

#include "transformation.hpp"

class Transformation2D final : public Transformation
{
public:
	explicit Transformation2D(float scale);

	~Transformation2D() override;

	Vector2f &Position();

	Vector2f &Scale();

	float &Rotation();

	[[nodiscard]] Matrix4f GetTransformation() const override;

private:
	Vector2f m_position;
	Vector2f m_scale;
	float m_rotation;
};

#endif //TRANSFORMATION_2_D_HPP
