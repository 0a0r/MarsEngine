#include "Engine/Graphics/Rgba.hpp"
#include <cmath>

float* Rgba8::ConvertRgba8ToFloat4(Rgba8 const& colorRgba8)
{
	auto normalizeByte = [&](unsigned char c)
	{
		return static_cast<float>(c) / 255.f;
	};

	float* colorFloat4 = new float[4];

	colorFloat4[0] = normalizeByte(colorRgba8.r);
	colorFloat4[1] = normalizeByte(colorRgba8.g);
	colorFloat4[2] = normalizeByte(colorRgba8.b);
	colorFloat4[3] = normalizeByte(colorRgba8.a);

	return colorFloat4;
}

Rgba8 Rgba8::ConvertFloat4ToRgba8(float const* colorFloat4)
{
	static float eps = 0.000001f;

	auto denormalizeByte = [&](float c)
	{
		// float c = Clamp<float>(x, 0.f, 1.f);
		if (fabs(c - 1.f) <= eps)
		{
			c = 255.f;
		}
		else
		{
			c *= 256.f;
		}
		return static_cast<unsigned char>(c);
	};

	Rgba8 colorRgba8;
	colorRgba8.r = denormalizeByte(colorFloat4[0]);
	colorRgba8.g = denormalizeByte(colorFloat4[1]);
	colorRgba8.b = denormalizeByte(colorFloat4[2]);
	colorRgba8.a = denormalizeByte(colorFloat4[3]);

	return colorRgba8;
}