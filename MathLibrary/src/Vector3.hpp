#pragma once

namespace Math
{
	struct Vector3
	{
		float x = 0.f, y = 0.f, z = 0.f;

		Vector3() {}
		Vector3(Vector3 const& copyFrom);
		~Vector3() {}

		float	Length() const;
		float	LengthSquared() const;
		void	Normalized();
		Vector3	GetNormalized() const;
	};
}