#include "mathpch.h"

namespace Math
{
	Matrix44::Matrix44()
	{
		// Identity default
		mValues[Ix] = 1.f;
		mValues[Jy] = 1.f;
		mValues[Kz] = 1.f;
		mValues[Tw] = 1.f;
	}

	Matrix44::Matrix44(Vector2 const& iBasis2D, Vector2 const& jBasis2D, Vector2 const& translation2D)
		: Matrix44()
	{
		mRowValues[0].xy = iBasis2D;
		mRowValues[1].xy = jBasis2D;
		mRowValues[3].xy = translation2D;
	}

	Matrix44::Matrix44(Vector3 const& iBasis3D, Vector3 const& jBasis3D, Vector3 const& kBasis3D, Vector3 const& translation3D)
		: Matrix44()
	{
		mRowValues[0].xyz = iBasis3D;
		mRowValues[1].xyz = jBasis3D;
		mRowValues[2].xyz = kBasis3D;
		mRowValues[3].xyz = translation3D;
	}

	Matrix44::Matrix44(Vector4 const& iBasis4D, Vector4 const& jBasis4D, Vector4 const& kBasis4D, Vector4 const& translation4D)
		: Matrix44()
	{
		mRowValues[0] = iBasis4D;
		mRowValues[1] = jBasis4D;
		mRowValues[2] = kBasis4D;
		mRowValues[3] = translation4D;
	}
}