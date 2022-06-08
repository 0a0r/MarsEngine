#pragma once

#include "Vector4.hpp"

namespace Math
{
	struct Vector2;
	struct Vector3;
	struct Matrix44
	{
		enum {
			Ix, Iy, Iz, Iw,
			Jx, Jy, Jz, Jw,
			Kx, Ky, Kz, Kw,
			Tx, Ty, Tz, Tw
		};

		union 
		{
			float	mValues[16] = { 0 };
			Vector4 mRowValues[4];
		};

		Vector4& operator[](size_t i) const
		{
			return (Vector4&)mRowValues[i];
		}

		Matrix44();
		~Matrix44() {}

		explicit Matrix44(Vector2 const& iBasis2D, Vector2 const& jBasis2D, Vector2 const& translation2D);
		explicit Matrix44(Vector3 const& iBasis3D, Vector3 const& jBasis3D, Vector3 const& kBasis3D, Vector3 const& translation3D);
		explicit Matrix44(Vector4 const& iBasis4D, Vector4 const& jBasis4D, Vector4 const& kBasis4D, Vector4 const& translation4D);
	};
}