#pragma once

namespace Math
{
	struct Vector2
	{
		float x = 0.f, y = 0.f;

		Vector2() {}
		Vector2(Vector2 const& copyFrom);
		~Vector2() {}

		float	Length() const;
		float	LengthSquared() const;
		void	Normalized();
		Vector2	GetNormalized() const;
	};
}