#include "mathpch.h"

namespace Math
{
	Vector4::Vector4(Vector4 const& copyFrom)
		: x(copyFrom.x), y(copyFrom.y), z(copyFrom.z), w(copyFrom.w) {}
}