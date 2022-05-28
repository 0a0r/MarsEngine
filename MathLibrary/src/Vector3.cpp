#include "mathpch.h"

namespace Math
{
	Vector3::Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) {}

	Vector3::Vector3(Vector3 const& copyFrom)
		: x(copyFrom.x), y(copyFrom.y), z(copyFrom.z) {}

	float Math::Vector3::Length() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	float Math::Vector3::LengthSquared() const
	{
		return x * x + y * y + z * z;
	}

	void Math::Vector3::Normalized()
	{
		// #ToDo: Fix the bug if length == 0
		float len = Length();
		x /= len;
		y /= len;
		z /= len;
	}

	Vector3 Math::Vector3::GetNormalized() const
	{
		Vector3 copy = *this;
		copy.Normalized();
		return copy;
	}
}