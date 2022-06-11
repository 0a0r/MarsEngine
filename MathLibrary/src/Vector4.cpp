#include "mathpch.h"

namespace Math
{
	Vector4::Vector4(float _x, float _y, float _z, float _w)
		: x(_x), y(_y), z(_z), w(_w) {}

	Vector4::Vector4(Vector4 const& copyFrom)
		: x(copyFrom.x), y(copyFrom.y), z(copyFrom.z), w(copyFrom.w) {}
	
	bool Vector4::operator==(Vector4 const& rhs) const
	{
		return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
	}
}