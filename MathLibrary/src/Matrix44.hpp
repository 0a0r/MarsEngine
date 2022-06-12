#pragma once

#include "Vector4.hpp"

namespace Math
{
	struct Vector2;
	struct Vector3;
	struct Matrix44
	{
		static Matrix44 const identity;
		static Matrix44 const zero;

		static Matrix44 GetTranspose(Matrix44 const& M);
		static Matrix44 GetInverse(Matrix44 const& M);
		static Matrix44 GetAdjugate(Matrix44 const& M);
		static float	GetDeterminant(Matrix44 const& M, int n = 4);

	private:
		enum {
			I, J, K, T
		};

		enum {
			Ix, Iy, Iz, Iw,
			Jx, Jy, Jz, Jw,
			Kx, Ky, Kz, Kw,
			Tx, Ty, Tz, Tw,
		};

		union 
		{
			float	mValues[16] = { 0 };
			Vector4 mRowValues[4];
		};

		static float LaplaceExpansion(Matrix44 const& M, int n = 4);

	public:
		Matrix44();
		~Matrix44() {}
		Matrix44(Matrix44 const& rhs);

		Vector4& operator[](int i) const
		{
			return (Vector4&)mRowValues[i];
		}

		explicit Matrix44(Vector2 const& iBasis2D, Vector2 const& jBasis2D, Vector2 const& translation2D);
		explicit Matrix44(Vector3 const& iBasis3D, Vector3 const& jBasis3D, Vector3 const& kBasis3D, Vector3 const& translation3D);
		explicit Matrix44(Vector4 const& iBasis4D, Vector4 const& jBasis4D, Vector4 const& kBasis4D, Vector4 const& translation4D);
	
		Vector4 operator*(Vector4 const& v) const
		{
			Vector4 result;
			result.x = mValues[Ix] * v.x + mValues[Jx] * v.y + mValues[Kx] * v.z + mValues[Tx] * v.w;
			result.y = mValues[Iy] * v.x + mValues[Jy] * v.y + mValues[Ky] * v.z + mValues[Ty] * v.w;
			result.z = mValues[Iz] * v.x + mValues[Jz] * v.y + mValues[Kz] * v.z + mValues[Tz] * v.w;
			result.w = mValues[Iw] * v.x + mValues[Jw] * v.y + mValues[Kw] * v.z + mValues[Tw] * v.w;
			return result;
		}

		Matrix44 operator*(Matrix44 const& rhs) const
		{
			Matrix44 const& mat = *this;
			Matrix44 result = Matrix44::zero;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					result[i][j] = (mat[i][0] * rhs[0][j] +
									mat[i][1] * rhs[1][j] +
									mat[i][2] * rhs[2][j] +
									mat[i][3] * rhs[3][j]);
				}
			}
			return result;
		}

		bool operator == (Matrix44 const& rhs) const
		{
			bool result = true;
			for (int i = 0; i < 16; i++)
			{
				if (mValues[i] != rhs.mValues[i])
				{
					result = false;
				}
			}
			return result;
		}

		Vector3 TransformPoint(Vector3 const& point) const;
		Vector3 TransformVector(Vector3 const& vector) const;
		void	Transpose();
		void	Inverse();
 	};
}