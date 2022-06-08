#pragma once

namespace Math
{
	struct Matrix44
	{
		enum {
			Ix, Iy, Iz, Iw,
			Jx, Jy, Jz, Jw,
			Kx, Ky, Kz, Kw,
			Tx, Ty, Tz, Tw
		};

		float mValues[16] = { 0 };

		Matrix44();
	};
}