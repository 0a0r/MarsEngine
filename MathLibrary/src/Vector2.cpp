#include "mathpch.h"

namespace Math
{
	Vector2::Vector2(float _x, float _y)
		: x(_x), y(_y) {}

	Vector2::Vector2(Vector2 const& copyFrom)
		: x(copyFrom.x), y(copyFrom.y) {}

	float Math::Vector2::Length() const
	{
		return sqrt(x * x + y * y);
	}

	float Math::Vector2::LengthSquared() const
	{
		return x * x + y * y;
	}

	void Math::Vector2::Normalized()
	{
		// #ToDo: Fix the bug if length == 0
		float len = Length();
		x /= len;
		y /= len;
	}

	Vector2 Math::Vector2::GetNormalized() const
	{
		Vector2 copy = *this;
		copy.Normalized();
		return copy;
	}
}