#pragma once

#include "MathCommon.hpp"

namespace Math
{
	struct Vector2;
	struct Vector3;
	struct Vector4
	{
		union {
			struct { float x, y, z, w; };

			// Swizzling
			float mData[4];

			_swizzle<Vector2, float, 0, 0> xx;
			_swizzle<Vector2, float, 0, 1> xy;
			_swizzle<Vector2, float, 0, 2> xz;
			_swizzle<Vector2, float, 0, 3> xw;
			_swizzle<Vector2, float, 1, 0> yx;
			_swizzle<Vector2, float, 1, 1> yy;
			_swizzle<Vector2, float, 1, 2> yz;
			_swizzle<Vector2, float, 1, 3> yw;
			_swizzle<Vector2, float, 2, 0> zx;
			_swizzle<Vector2, float, 2, 1> zy;
			_swizzle<Vector2, float, 2, 2> zz;
			_swizzle<Vector2, float, 2, 3> zw;
			_swizzle<Vector2, float, 3, 0> wx;
			_swizzle<Vector2, float, 3, 1> wy;
			_swizzle<Vector2, float, 3, 2> wz;
			_swizzle<Vector2, float, 3, 3> ww;

			_swizzle<Vector3, float, 0, 0, 0> xxx;
			_swizzle<Vector3, float, 0, 1, 0> xyx;
			_swizzle<Vector3, float, 0, 2, 0> xzx;
			_swizzle<Vector3, float, 0, 3, 0> xwx;
			_swizzle<Vector3, float, 1, 0, 0> yxx;
			_swizzle<Vector3, float, 1, 1, 0> yyx;
			_swizzle<Vector3, float, 1, 2, 0> yzx;
			_swizzle<Vector3, float, 1, 3, 0> ywx;
			_swizzle<Vector3, float, 2, 0, 0> zxx;
			_swizzle<Vector3, float, 2, 1, 0> zyx;
			_swizzle<Vector3, float, 2, 2, 0> zzx;
			_swizzle<Vector3, float, 2, 3, 0> zwx;
			_swizzle<Vector3, float, 3, 0, 0> wxx;
			_swizzle<Vector3, float, 3, 1, 0> wyx;
			_swizzle<Vector3, float, 3, 2, 0> wzx;
			_swizzle<Vector3, float, 3, 3, 0> wwx;

			_swizzle<Vector3, float, 0, 0, 1> xxy;
			_swizzle<Vector3, float, 0, 1, 1> xyy;
			_swizzle<Vector3, float, 0, 2, 1> xzy;
			_swizzle<Vector3, float, 0, 3, 1> xwy;
			_swizzle<Vector3, float, 1, 0, 1> yxy;
			_swizzle<Vector3, float, 1, 1, 1> yyy;
			_swizzle<Vector3, float, 1, 2, 1> yzy;
			_swizzle<Vector3, float, 1, 3, 1> ywy;
			_swizzle<Vector3, float, 2, 0, 1> zxy;
			_swizzle<Vector3, float, 2, 1, 1> zyy;
			_swizzle<Vector3, float, 2, 2, 1> zzy;
			_swizzle<Vector3, float, 2, 3, 1> zwy;
			_swizzle<Vector3, float, 3, 0, 1> wxy;
			_swizzle<Vector3, float, 3, 1, 1> wyy;
			_swizzle<Vector3, float, 3, 2, 1> wzy;
			_swizzle<Vector3, float, 3, 3, 1> wwy;

			_swizzle<Vector3, float, 0, 0, 2> xxz;
			_swizzle<Vector3, float, 0, 1, 2> xyz;
			_swizzle<Vector3, float, 0, 2, 2> xzz;
			_swizzle<Vector3, float, 0, 3, 2> xwz;
			_swizzle<Vector3, float, 1, 0, 2> yxz;
			_swizzle<Vector3, float, 1, 1, 2> yyz;
			_swizzle<Vector3, float, 1, 2, 2> yzz;
			_swizzle<Vector3, float, 1, 3, 2> ywz;
			_swizzle<Vector3, float, 2, 0, 2> zxz;
			_swizzle<Vector3, float, 2, 1, 2> zyz;
			_swizzle<Vector3, float, 2, 2, 2> zzz;
			_swizzle<Vector3, float, 2, 3, 2> zwz;
			_swizzle<Vector3, float, 3, 0, 2> wxz;
			_swizzle<Vector3, float, 3, 1, 2> wyz;
			_swizzle<Vector3, float, 3, 2, 2> wzz;
			_swizzle<Vector3, float, 3, 3, 2> wwz;

			_swizzle<Vector3, float, 0, 0, 3> xxw;
			_swizzle<Vector3, float, 0, 1, 3> xyw;
			_swizzle<Vector3, float, 0, 2, 3> xzw;
			_swizzle<Vector3, float, 0, 3, 3> xww;
			_swizzle<Vector3, float, 1, 0, 3> yxw;
			_swizzle<Vector3, float, 1, 1, 3> yyw;
			_swizzle<Vector3, float, 1, 2, 3> yzw;
			_swizzle<Vector3, float, 1, 3, 3> yww;
			_swizzle<Vector3, float, 2, 0, 3> zxw;
			_swizzle<Vector3, float, 2, 1, 3> zyw;
			_swizzle<Vector3, float, 2, 2, 3> zzw;
			_swizzle<Vector3, float, 2, 3, 3> zww;
			_swizzle<Vector3, float, 3, 0, 3> wxw;
			_swizzle<Vector3, float, 3, 1, 3> wyw;
			_swizzle<Vector3, float, 3, 2, 3> wzw;
			_swizzle<Vector3, float, 3, 3, 3> www;

			_swizzle<Vector4, float, 0, 0, 0, 0> xxxx;
			_swizzle<Vector4, float, 0, 1, 0, 0> xyxx;
			_swizzle<Vector4, float, 0, 2, 0, 0> xzxx;
			_swizzle<Vector4, float, 0, 3, 0, 0> xwxx;
			_swizzle<Vector4, float, 1, 0, 0, 0> yxxx;
			_swizzle<Vector4, float, 1, 1, 0, 0> yyxx;
			_swizzle<Vector4, float, 1, 2, 0, 0> yzxx;
			_swizzle<Vector4, float, 1, 3, 0, 0> ywxx;
			_swizzle<Vector4, float, 2, 0, 0, 0> zxxx;
			_swizzle<Vector4, float, 2, 1, 0, 0> zyxx;
			_swizzle<Vector4, float, 2, 2, 0, 0> zzxx;
			_swizzle<Vector4, float, 2, 3, 0, 0> zwxx;
			_swizzle<Vector4, float, 3, 0, 0, 0> wxxx;
			_swizzle<Vector4, float, 3, 1, 0, 0> wyxx;
			_swizzle<Vector4, float, 3, 2, 0, 0> wzxx;
			_swizzle<Vector4, float, 3, 3, 0, 0> wwxx;

			_swizzle<Vector4, float, 0, 0, 1, 0> xxyx;
			_swizzle<Vector4, float, 0, 1, 1, 0> xyyx;
			_swizzle<Vector4, float, 0, 2, 1, 0> xzyx;
			_swizzle<Vector4, float, 0, 3, 1, 0> xwyx;
			_swizzle<Vector4, float, 1, 0, 1, 0> yxyx;
			_swizzle<Vector4, float, 1, 1, 1, 0> yyyx;
			_swizzle<Vector4, float, 1, 2, 1, 0> yzyx;
			_swizzle<Vector4, float, 1, 3, 1, 0> ywyx;
			_swizzle<Vector4, float, 2, 0, 1, 0> zxyx;
			_swizzle<Vector4, float, 2, 1, 1, 0> zyyx;
			_swizzle<Vector4, float, 2, 2, 1, 0> zzyx;
			_swizzle<Vector4, float, 2, 3, 1, 0> zwyx;
			_swizzle<Vector4, float, 3, 0, 1, 0> wxyx;
			_swizzle<Vector4, float, 3, 1, 1, 0> wyyx;
			_swizzle<Vector4, float, 3, 2, 1, 0> wzyx;
			_swizzle<Vector4, float, 3, 3, 1, 0> wwyx;

			_swizzle<Vector4, float, 0, 0, 2, 0> xxzx;
			_swizzle<Vector4, float, 0, 1, 2, 0> xyzx;
			_swizzle<Vector4, float, 0, 2, 2, 0> xzzx;
			_swizzle<Vector4, float, 0, 3, 2, 0> xwzx;
			_swizzle<Vector4, float, 1, 0, 2, 0> yxzx;
			_swizzle<Vector4, float, 1, 1, 2, 0> yyzx;
			_swizzle<Vector4, float, 1, 2, 2, 0> yzzx;
			_swizzle<Vector4, float, 1, 3, 2, 0> ywzx;
			_swizzle<Vector4, float, 2, 0, 2, 0> zxzx;
			_swizzle<Vector4, float, 2, 1, 2, 0> zyzx;
			_swizzle<Vector4, float, 2, 2, 2, 0> zzzx;
			_swizzle<Vector4, float, 2, 3, 2, 0> zwzx;
			_swizzle<Vector4, float, 3, 0, 2, 0> wxzx;
			_swizzle<Vector4, float, 3, 1, 2, 0> wyzx;
			_swizzle<Vector4, float, 3, 2, 2, 0> wzzx;
			_swizzle<Vector4, float, 3, 3, 2, 0> wwzx;

			_swizzle<Vector4, float, 0, 0, 3, 0> xxwx;
			_swizzle<Vector4, float, 0, 1, 3, 0> xywx;
			_swizzle<Vector4, float, 0, 2, 3, 0> xzwx;
			_swizzle<Vector4, float, 0, 3, 3, 0> xwwx;
			_swizzle<Vector4, float, 1, 0, 3, 0> yxwx;
			_swizzle<Vector4, float, 1, 1, 3, 0> yywx;
			_swizzle<Vector4, float, 1, 2, 3, 0> yzwx;
			_swizzle<Vector4, float, 1, 3, 3, 0> ywwx;
			_swizzle<Vector4, float, 2, 0, 3, 0> zxwx;
			_swizzle<Vector4, float, 2, 1, 3, 0> zywx;
			_swizzle<Vector4, float, 2, 2, 3, 0> zzwx;
			_swizzle<Vector4, float, 2, 3, 3, 0> zwwx;
			_swizzle<Vector4, float, 3, 0, 3, 0> wxwx;
			_swizzle<Vector4, float, 3, 1, 3, 0> wywx;
			_swizzle<Vector4, float, 3, 2, 3, 0> wzwx;
			_swizzle<Vector4, float, 3, 3, 3, 0> wwwx;

			_swizzle<Vector4, float, 0, 0, 0, 1> xxxy;
			_swizzle<Vector4, float, 0, 1, 0, 1> xyxy;
			_swizzle<Vector4, float, 0, 2, 0, 1> xzxy;
			_swizzle<Vector4, float, 0, 3, 0, 1> xwxy;
			_swizzle<Vector4, float, 1, 0, 0, 1> yxxy;
			_swizzle<Vector4, float, 1, 1, 0, 1> yyxy;
			_swizzle<Vector4, float, 1, 2, 0, 1> yzxy;
			_swizzle<Vector4, float, 1, 3, 0, 1> ywxy;
			_swizzle<Vector4, float, 2, 0, 0, 1> zxxy;
			_swizzle<Vector4, float, 2, 1, 0, 1> zyxy;
			_swizzle<Vector4, float, 2, 2, 0, 1> zzxy;
			_swizzle<Vector4, float, 2, 3, 0, 1> zwxy;
			_swizzle<Vector4, float, 3, 0, 0, 1> wxxy;
			_swizzle<Vector4, float, 3, 1, 0, 1> wyxy;
			_swizzle<Vector4, float, 3, 2, 0, 1> wzxy;
			_swizzle<Vector4, float, 3, 3, 0, 1> wwxy;
			
			_swizzle<Vector4, float, 0, 0, 1, 1> xxyy;
			_swizzle<Vector4, float, 0, 1, 1, 1> xyyy;
			_swizzle<Vector4, float, 0, 2, 1, 1> xzyy;
			_swizzle<Vector4, float, 0, 3, 1, 1> xwyy;
			_swizzle<Vector4, float, 1, 0, 1, 1> yxyy;
			_swizzle<Vector4, float, 1, 1, 1, 1> yyyy;
			_swizzle<Vector4, float, 1, 2, 1, 1> yzyy;
			_swizzle<Vector4, float, 1, 3, 1, 1> ywyy;
			_swizzle<Vector4, float, 2, 0, 1, 1> zxyy;
			_swizzle<Vector4, float, 2, 1, 1, 1> zyyy;
			_swizzle<Vector4, float, 2, 2, 1, 1> zzyy;
			_swizzle<Vector4, float, 2, 3, 1, 1> zwyy;
			_swizzle<Vector4, float, 3, 0, 1, 1> wxyy;
			_swizzle<Vector4, float, 3, 1, 1, 1> wyyy;
			_swizzle<Vector4, float, 3, 2, 1, 1> wzyy;
			_swizzle<Vector4, float, 3, 3, 1, 1> wwyy;
			
			_swizzle<Vector4, float, 0, 0, 2, 1> xxzy;
			_swizzle<Vector4, float, 0, 1, 2, 1> xyzy;
			_swizzle<Vector4, float, 0, 2, 2, 1> xzzy;
			_swizzle<Vector4, float, 0, 3, 2, 1> xwzy;
			_swizzle<Vector4, float, 1, 0, 2, 1> yxzy;
			_swizzle<Vector4, float, 1, 1, 2, 1> yyzy;
			_swizzle<Vector4, float, 1, 2, 2, 1> yzzy;
			_swizzle<Vector4, float, 1, 3, 2, 1> ywzy;
			_swizzle<Vector4, float, 2, 0, 2, 1> zxzy;
			_swizzle<Vector4, float, 2, 1, 2, 1> zyzy;
			_swizzle<Vector4, float, 2, 2, 2, 1> zzzy;
			_swizzle<Vector4, float, 2, 3, 2, 1> zwzy;
			_swizzle<Vector4, float, 3, 0, 2, 1> wxzy;
			_swizzle<Vector4, float, 3, 1, 2, 1> wyzy;
			_swizzle<Vector4, float, 3, 2, 2, 1> wzzy;
			_swizzle<Vector4, float, 3, 3, 2, 1> wwzy;
			
			_swizzle<Vector4, float, 0, 0, 3, 1> xxwy;
			_swizzle<Vector4, float, 0, 1, 3, 1> xywy;
			_swizzle<Vector4, float, 0, 2, 3, 1> xzwy;
			_swizzle<Vector4, float, 0, 3, 3, 1> xwwy;
			_swizzle<Vector4, float, 1, 0, 3, 1> yxwy;
			_swizzle<Vector4, float, 1, 1, 3, 1> yywy;
			_swizzle<Vector4, float, 1, 2, 3, 1> yzwy;
			_swizzle<Vector4, float, 1, 3, 3, 1> ywwy;
			_swizzle<Vector4, float, 2, 0, 3, 1> zxwy;
			_swizzle<Vector4, float, 2, 1, 3, 1> zywy;
			_swizzle<Vector4, float, 2, 2, 3, 1> zzwy;
			_swizzle<Vector4, float, 2, 3, 3, 1> zwwy;
			_swizzle<Vector4, float, 3, 0, 3, 1> wxwy;
			_swizzle<Vector4, float, 3, 1, 3, 1> wywy;
			_swizzle<Vector4, float, 3, 2, 3, 1> wzwy;
			_swizzle<Vector4, float, 3, 3, 3, 1> wwwy;

			_swizzle<Vector4, float, 0, 0, 0, 2> xxxz;
			_swizzle<Vector4, float, 0, 1, 0, 2> xyxz;
			_swizzle<Vector4, float, 0, 2, 0, 2> xzxz;
			_swizzle<Vector4, float, 0, 3, 0, 2> xwxz;
			_swizzle<Vector4, float, 1, 0, 0, 2> yxxz;
			_swizzle<Vector4, float, 1, 1, 0, 2> yyxz;
			_swizzle<Vector4, float, 1, 2, 0, 2> yzxz;
			_swizzle<Vector4, float, 1, 3, 0, 2> ywxz;
			_swizzle<Vector4, float, 2, 0, 0, 2> zxxz;
			_swizzle<Vector4, float, 2, 1, 0, 2> zyxz;
			_swizzle<Vector4, float, 2, 2, 0, 2> zzxz;
			_swizzle<Vector4, float, 2, 3, 0, 2> zwxz;
			_swizzle<Vector4, float, 3, 0, 0, 2> wxxz;
			_swizzle<Vector4, float, 3, 1, 0, 2> wyxz;
			_swizzle<Vector4, float, 3, 2, 0, 2> wzxz;
			_swizzle<Vector4, float, 3, 3, 0, 2> wwxz;
			
			_swizzle<Vector4, float, 0, 0, 1, 2> xxyz;
			_swizzle<Vector4, float, 0, 1, 1, 2> xyyz;
			_swizzle<Vector4, float, 0, 2, 1, 2> xzyz;
			_swizzle<Vector4, float, 0, 3, 1, 2> xwyz;
			_swizzle<Vector4, float, 1, 0, 1, 2> yxyz;
			_swizzle<Vector4, float, 1, 1, 1, 2> yyyz;
			_swizzle<Vector4, float, 1, 2, 1, 2> yzyz;
			_swizzle<Vector4, float, 1, 3, 1, 2> ywyz;
			_swizzle<Vector4, float, 2, 0, 1, 2> zxyz;
			_swizzle<Vector4, float, 2, 1, 1, 2> zyyz;
			_swizzle<Vector4, float, 2, 2, 1, 2> zzyz;
			_swizzle<Vector4, float, 2, 3, 1, 2> zwyz;
			_swizzle<Vector4, float, 3, 0, 1, 2> wxyz;
			_swizzle<Vector4, float, 3, 1, 1, 2> wyyz;
			_swizzle<Vector4, float, 3, 2, 1, 2> wzyz;
			_swizzle<Vector4, float, 3, 3, 1, 2> wwyz;
			
			_swizzle<Vector4, float, 0, 0, 2, 2> xxzz;
			_swizzle<Vector4, float, 0, 1, 2, 2> xyzz;
			_swizzle<Vector4, float, 0, 2, 2, 2> xzzz;
			_swizzle<Vector4, float, 0, 3, 2, 2> xwzz;
			_swizzle<Vector4, float, 1, 0, 2, 2> yxzz;
			_swizzle<Vector4, float, 1, 1, 2, 2> yyzz;
			_swizzle<Vector4, float, 1, 2, 2, 2> yzzz;
			_swizzle<Vector4, float, 1, 3, 2, 2> ywzz;
			_swizzle<Vector4, float, 2, 0, 2, 2> zxzz;
			_swizzle<Vector4, float, 2, 1, 2, 2> zyzz;
			_swizzle<Vector4, float, 2, 2, 2, 2> zzzz;
			_swizzle<Vector4, float, 2, 3, 2, 2> zwzz;
			_swizzle<Vector4, float, 3, 0, 2, 2> wxzz;
			_swizzle<Vector4, float, 3, 1, 2, 2> wyzz;
			_swizzle<Vector4, float, 3, 2, 2, 2> wzzz;
			_swizzle<Vector4, float, 3, 3, 2, 2> wwzz;
				
			_swizzle<Vector4, float, 0, 0, 3, 2> xxwz;
			_swizzle<Vector4, float, 0, 1, 3, 2> xywz;
			_swizzle<Vector4, float, 0, 2, 3, 2> xzwz;
			_swizzle<Vector4, float, 0, 3, 3, 2> xwwz;
			_swizzle<Vector4, float, 1, 0, 3, 2> yxwz;
			_swizzle<Vector4, float, 1, 1, 3, 2> yywz;
			_swizzle<Vector4, float, 1, 2, 3, 2> yzwz;
			_swizzle<Vector4, float, 1, 3, 3, 2> ywwz;
			_swizzle<Vector4, float, 2, 0, 3, 2> zxwz;
			_swizzle<Vector4, float, 2, 1, 3, 2> zywz;
			_swizzle<Vector4, float, 2, 2, 3, 2> zzwz;
			_swizzle<Vector4, float, 2, 3, 3, 2> zwwz;
			_swizzle<Vector4, float, 3, 0, 3, 2> wxwz;
			_swizzle<Vector4, float, 3, 1, 3, 2> wywz;
			_swizzle<Vector4, float, 3, 2, 3, 2> wzwz;
			_swizzle<Vector4, float, 3, 3, 3, 2> wwwz;

			_swizzle<Vector4, float, 0, 0, 0, 3> xxxw;
			_swizzle<Vector4, float, 0, 1, 0, 3> xyxw;
			_swizzle<Vector4, float, 0, 2, 0, 3> xzxw;
			_swizzle<Vector4, float, 0, 3, 0, 3> xwxw;
			_swizzle<Vector4, float, 1, 0, 0, 3> yxxw;
			_swizzle<Vector4, float, 1, 1, 0, 3> yyxw;
			_swizzle<Vector4, float, 1, 2, 0, 3> yzxw;
			_swizzle<Vector4, float, 1, 3, 0, 3> ywxw;
			_swizzle<Vector4, float, 2, 0, 0, 3> zxxw;
			_swizzle<Vector4, float, 2, 1, 0, 3> zyxw;
			_swizzle<Vector4, float, 2, 2, 0, 3> zzxw;
			_swizzle<Vector4, float, 2, 3, 0, 3> zwxw;
			_swizzle<Vector4, float, 3, 0, 0, 3> wxxw;
			_swizzle<Vector4, float, 3, 1, 0, 3> wyxw;
			_swizzle<Vector4, float, 3, 2, 0, 3> wzxw;
			_swizzle<Vector4, float, 3, 3, 0, 3> wwxw;

			_swizzle<Vector4, float, 0, 0, 1, 3> xxyw;
			_swizzle<Vector4, float, 0, 1, 1, 3> xyyw;
			_swizzle<Vector4, float, 0, 2, 1, 3> xzyw;
			_swizzle<Vector4, float, 0, 3, 1, 3> xwyw;
			_swizzle<Vector4, float, 1, 0, 1, 3> yxyw;
			_swizzle<Vector4, float, 1, 1, 1, 3> yyyw;
			_swizzle<Vector4, float, 1, 2, 1, 3> yzyw;
			_swizzle<Vector4, float, 1, 3, 1, 3> ywyw;
			_swizzle<Vector4, float, 2, 0, 1, 3> zxyw;
			_swizzle<Vector4, float, 2, 1, 1, 3> zyyw;
			_swizzle<Vector4, float, 2, 2, 1, 3> zzyw;
			_swizzle<Vector4, float, 2, 3, 1, 3> zwyw;
			_swizzle<Vector4, float, 3, 0, 1, 3> wxyw;
			_swizzle<Vector4, float, 3, 1, 1, 3> wyyw;
			_swizzle<Vector4, float, 3, 2, 1, 3> wzyw;
			_swizzle<Vector4, float, 3, 3, 1, 3> wwyw;

			_swizzle<Vector4, float, 0, 0, 2, 3> xxzw;
			_swizzle<Vector4, float, 0, 1, 2, 3> xyzw;
			_swizzle<Vector4, float, 0, 2, 2, 3> xzzw;
			_swizzle<Vector4, float, 0, 3, 2, 3> xwzw;
			_swizzle<Vector4, float, 1, 0, 2, 3> yxzw;
			_swizzle<Vector4, float, 1, 1, 2, 3> yyzw;
			_swizzle<Vector4, float, 1, 2, 2, 3> yzzw;
			_swizzle<Vector4, float, 1, 3, 2, 3> ywzw;
			_swizzle<Vector4, float, 2, 0, 2, 3> zxzw;
			_swizzle<Vector4, float, 2, 1, 2, 3> zyzw;
			_swizzle<Vector4, float, 2, 2, 2, 3> zzzw;
			_swizzle<Vector4, float, 2, 3, 2, 3> zwzw;
			_swizzle<Vector4, float, 3, 0, 2, 3> wxzw;
			_swizzle<Vector4, float, 3, 1, 2, 3> wyzw;
			_swizzle<Vector4, float, 3, 2, 2, 3> wzzw;
			_swizzle<Vector4, float, 3, 3, 2, 3> wwzw;

			_swizzle<Vector4, float, 0, 0, 3, 3> xxww;
			_swizzle<Vector4, float, 0, 1, 3, 3> xyww;
			_swizzle<Vector4, float, 0, 2, 3, 3> xzww;
			_swizzle<Vector4, float, 0, 3, 3, 3> xwww;
			_swizzle<Vector4, float, 1, 0, 3, 3> yxww;
			_swizzle<Vector4, float, 1, 1, 3, 3> yyww;
			_swizzle<Vector4, float, 1, 2, 3, 3> yzww;
			_swizzle<Vector4, float, 1, 3, 3, 3> ywww;
			_swizzle<Vector4, float, 2, 0, 3, 3> zxww;
			_swizzle<Vector4, float, 2, 1, 3, 3> zyww;
			_swizzle<Vector4, float, 2, 2, 3, 3> zzww;
			_swizzle<Vector4, float, 2, 3, 3, 3> zwww;
			_swizzle<Vector4, float, 3, 0, 3, 3> wxww;
			_swizzle<Vector4, float, 3, 1, 3, 3> wyww;
			_swizzle<Vector4, float, 3, 2, 3, 3> wzww;
			_swizzle<Vector4, float, 3, 3, 3, 3> wwww;
		};

		Vector4() {}
		Vector4(float _x, float _y, float _z, float _w);
		Vector4(Vector4 const& copyFrom);
		~Vector4() {}

		float& operator[] (int i)
		{
			// #ToDo: Add error handling logic in here
			if (i == 0) return x;
			else if (i == 1) return y;
			else if (i == 2) return z;
			else return w;
		}

		operator float* () { return mData; };
		operator const float* () const { return static_cast<const float*>(mData); };
		bool operator == (Vector4 const& rhs) const;
	};
}