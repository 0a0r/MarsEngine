#pragma once

#include "MathCommon.hpp"

namespace Math
{
	struct Vector2;
	struct Vector3
	{
		union {
			struct { float x, y, z; };
			
			// Swizzling
			float mData[3];

			_swizzle<Vector2, float, 0, 0> xx;
			_swizzle<Vector2, float, 0, 1> xy;
			_swizzle<Vector2, float, 0, 2> xz;
			_swizzle<Vector2, float, 1, 0> yx;
			_swizzle<Vector2, float, 1, 1> yy;
			_swizzle<Vector2, float, 1, 2> yz;
			_swizzle<Vector2, float, 2, 0> zx;
			_swizzle<Vector2, float, 2, 1> zy;
			_swizzle<Vector2, float, 2, 2> zz;

			_swizzle<Vector3, float, 0, 0, 0> xxx;
			_swizzle<Vector3, float, 0, 1, 0> xyx;
			_swizzle<Vector3, float, 0, 2, 0> xzx;
			_swizzle<Vector3, float, 1, 0, 0> yxx;
			_swizzle<Vector3, float, 1, 1, 0> yyx;
			_swizzle<Vector3, float, 1, 2, 0> yzx;
			_swizzle<Vector3, float, 2, 0, 0> zxx;
			_swizzle<Vector3, float, 2, 1, 0> zyx;
			_swizzle<Vector3, float, 2, 2, 0> zzx;

			_swizzle<Vector3, float, 0, 0, 1> xxy;
			_swizzle<Vector3, float, 0, 1, 1> xyy;
			_swizzle<Vector3, float, 0, 2, 1> xzy;
			_swizzle<Vector3, float, 1, 0, 1> yxy;
			_swizzle<Vector3, float, 1, 1, 1> yyy;
			_swizzle<Vector3, float, 1, 2, 1> yzy;
			_swizzle<Vector3, float, 2, 0, 1> zxy;
			_swizzle<Vector3, float, 2, 1, 1> zyy;
			_swizzle<Vector3, float, 2, 2, 1> zzy;

			_swizzle<Vector3, float, 0, 0, 2> xxz;
			_swizzle<Vector3, float, 0, 1, 2> xyz;
			_swizzle<Vector3, float, 0, 2, 2> xzz;
			_swizzle<Vector3, float, 1, 0, 2> yxz;
			_swizzle<Vector3, float, 1, 1, 2> yyz;
			_swizzle<Vector3, float, 1, 2, 2> yzz;
			_swizzle<Vector3, float, 2, 0, 2> zxz;
			_swizzle<Vector3, float, 2, 1, 2> zyz;
			_swizzle<Vector3, float, 2, 2, 2> zzz;
		};

		Vector3() {}
		Vector3(float _x, float _y, float _z);
		Vector3(Vector3 const& copyFrom);
		~Vector3() {}

		operator float* () { return mData; };
		operator const float* () const { return static_cast<const float*>(mData); };

		float	Length() const;
		float	LengthSquared() const;
		void	Normalized();
		Vector3	GetNormalized() const;
	};
}