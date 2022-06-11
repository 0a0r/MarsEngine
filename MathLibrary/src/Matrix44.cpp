#include "mathpch.h"

namespace Math
{
	const Matrix44 Matrix44::identity = Matrix44(Vector4(1.f, 0.f, 0.f, 0.f), Vector4(0.f, 1.f, 0.f, 0.f), Vector4(0.f, 0.f, 1.f, 0.f), Vector4(0.f, 0.f, 0.f, 1.f));
	const Matrix44 Matrix44::zero = Matrix44(Vector4(0.f, 0.f, 0.f, 0.f), Vector4(0.f, 0.f, 0.f, 0.f), Vector4(0.f, 0.f, 0.f, 0.f), Vector4(0.f, 0.f, 0.f, 0.f));

	Matrix44 Matrix44::GetTranspose(Matrix44 const& M)
	{
		Matrix44 result = M;
		result.Transpose();
		return result;
	}

	Matrix44 Matrix44::GetInverse(Matrix44 const& M)
	{
		Matrix44 result = M;
		float determiant = Matrix44::GetDeterminant(M);
		if (determiant != 0.f)
		{
			Matrix44 adjMat = Matrix44::GetAdjugate(M);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					result[i][j] = adjMat[i][j] / determiant;
				}
			}
		}
		return result;
	}

	Matrix44 Matrix44::GetAdjugate(Matrix44 const& M)
	{
		Matrix44 temp = Matrix44::zero;
		Matrix44 adjM = Matrix44::zero;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					for (int w = 0; w < 3; w++)
					{
						temp[k][w] = M[k >= i ? k + 1 : k][w >= j ? w + 1 : w];
					}
				}
				adjM[i][j] = Matrix44::GetDeterminant(temp, 3);
				if ((i + j) & 1)
				{
					adjM[i][j] = -adjM[i][j];
				}
			}
		}
		return adjM;
	}

	float Matrix44::GetDeterminant(Matrix44 const& M, int n)
	{
		float determinant = Matrix44::LaplaceExpansion(M, n);
		return determinant;
	}

	float Matrix44::LaplaceExpansion(Matrix44 const& M, int n)
	{
		if (n == 1)
		{
			return M[I].x;
		}

		Matrix44 temp = Matrix44::zero;
		float determiant = 0.f;

		// Take first row
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				for (int k = 0; k < n - 1; k++)
				{
					temp[j][k] = M[j + 1][k >= i ? k + 1 : k];
				}
			}

			float subDetermiant = LaplaceExpansion(temp, n - 1);
			if (i & 1)
			{
				determiant -= M[0][i] * subDetermiant;
			}
			else
			{
				determiant += M[0][i] * subDetermiant;
			}
		}

		return determiant;
	}

	Matrix44::Matrix44()
	{
		// Identity default
		mRowValues[I].x = 1.f;
		mRowValues[J].y = 1.f;
		mRowValues[K].z = 1.f;
		mRowValues[T].w = 1.f;
	}

	Matrix44::Matrix44(Matrix44 const& rhs)
	{
		for(int i = 0; i < 4; i++)
		{
			(*this)[i] = rhs[i];
		}
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

	Vector3 Matrix44::TransformPoint(Vector3 const& point) const
	{
		Vector4 h;
		h.xyz = point;
		h.w = 1.0f;
		return (*this * h).xyz;
	}

	Vector3 Matrix44::TransformVector(Vector3 const& vector) const
	{
		Vector4 h;
		h.xyz = vector;
		h.w = 0.f;
		return (*this * h).xyz;
	}

	void Matrix44::Transpose()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < i; j++)
			{
				float t = mValues[i * 4 + j];
				mValues[i * 4 + j] = mValues[i + j * 4];
				mValues[i + j * 4] = t;
			}
		}
	}

	void Matrix44::Inverse()
	{
	}

	
}