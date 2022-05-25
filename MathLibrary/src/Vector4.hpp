#pragma once

namespace Math
{
	struct Vector4
	{
		float x = 0.f, y = 0.f, z = 0.f, w = 0.f;

		Vector4() {}
		Vector4(Vector4 const& copyFrom);
		~Vector4() {}
	};
}