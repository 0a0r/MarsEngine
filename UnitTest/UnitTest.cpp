#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Math;

namespace UnitTest
{
	TEST_CLASS(MathUnitTest)
	{
	public:
		TEST_METHOD(SwizzlingTest)
		{
			Vector2 testVec2(1.f, 2.f);
			Vector3 testVec3(3.f, 4.f, 5.f);
			Vector4 testVec4(6.f, 7.f, 8.f, 9.f);

			testVec2.yx = testVec3.yz;
			testVec4.wxz = testVec3.xyz;

			Vector2 resVec2 = Vector2(5.f, 4.f);
			Vector4 resVec4 = Vector4(4.f, 7.f, 5.f, 3.f);

			Assert::IsTrue(testVec2 == resVec2);
			Assert::IsTrue(testVec4 == resVec4);
		}

		TEST_METHOD(MatrixMultiplyMatrixTest)
		{
			Matrix44 matA = Matrix44(
				Vector4(1.f, 2.f, 3.f, 4.f),
				Vector4(5.f, 6.f, 7.f, 8.f),
				Vector4(9.f, 10.f, 11.f, 12.f),
				Vector4(13.f, 14.f, 15.f, 16.f)
			);

			Matrix44 matB = Matrix44(
				Vector4(16.f, 15.f, 14.f, 13.f),
				Vector4(12.f, 11.f, 10.f, 9.f),
				Vector4(8.f, 7.f, 6.f, 5.f),
				Vector4(4.f, 3.f, 2.f, 1.f)
			);

			Matrix44 result = Matrix44(
				Vector4(80.f, 70.f, 60.f, 50.f),
				Vector4(240.f, 214.f, 188.f, 162.f),
				Vector4(400.f, 358.f, 316.f, 274.f),
				Vector4(560.f, 502.f, 444.f, 386.f)
			);

			Assert::IsTrue(result == matA * matB);
		}

		TEST_METHOD(MatrixTransformTest)
		{
			Matrix44 matA = Matrix44(
				Vector4(2.f, 3.f, 4.f, 5.f),
				Vector4(6.f, 7.f, 8.f, 9.f),
				Vector4(10.f, 11.f, 12.f, 13.f),
				Vector4(14.f, 15.f, 16.f, 17.f)
			);

			Vector4 vecB = Vector4(7.f, 5.f, 3.f, 0.f);

			Vector4 result = Vector4(74.f, 89.f, 104.f, 119.f);

			Assert::IsTrue(result == matA.Transform(vecB));
		}

		TEST_METHOD(MatrixTransformVectorTest)
		{
			Matrix44 matA = Matrix44(
				Vector4(2.f, 3.f, 4.f, 5.f),
				Vector4(6.f, 7.f, 8.f, 9.f),
				Vector4(10.f, 11.f, 12.f, 13.f),
				Vector4(14.f, 15.f, 16.f, 17.f)
			);

			Vector3 vecB = Vector3(7.f, 5.f, 3.f);

			Vector3 result = Vector3(74.f, 89.f, 104.f);

			Assert::IsTrue(result == matA.TransformVector(vecB));
		}

		TEST_METHOD(MatrixTransformPointTest)
		{
			Matrix44 matA = Matrix44(
				Vector4(2.f, 3.f, 4.f, 5.f),
				Vector4(6.f, 7.f, 8.f, 9.f),
				Vector4(10.f, 11.f, 12.f, 13.f),
				Vector4(14.f, 15.f, 16.f, 17.f)
			);

			Vector3 posB = Vector3(7.f, 5.f, 3.f);

			Vector3 result = Vector3(88.f, 104.f, 120.f);

			Assert::IsTrue(result == matA.TransformPoint(posB));
		}
	};
}
