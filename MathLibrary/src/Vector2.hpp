#pragma once

#include "MathCommon.hpp"

namespace Math
{
	struct Vector2
	{
		union {
			struct { float x, y; };
			
			// Swizzling
			float mData[2];

			_swizzle<Vector2, float, 0, 0> xx;
			_swizzle<Vector2, float, 0, 1> xy;
			_swizzle<Vector2, float, 1, 0> yx;
			_swizzle<Vector2, float, 1, 1> yy;
		};

		Vector2() {}
		Vector2(float _x, float _y);
		Vector2(Vector2 const& copyFrom);
		~Vector2() {}

		operator float* () { return mData; };
		operator const float* () const { return static_cast<const float*>(mData); };
		bool operator == (Vector2 const& rhs) const;

		float	Length() const;
		float	LengthSquared() const;
		void	Normalized();
		Vector2	GetNormalized() const;
	};
}