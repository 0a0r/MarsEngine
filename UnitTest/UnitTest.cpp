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
	};
}
