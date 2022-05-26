#pragma once

struct Rgba8
{
	unsigned char r = 255;
	unsigned char g = 255;
	unsigned char b = 255;
	unsigned char a = 255;

	Rgba8() {};
	Rgba8(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 255)
		: r(red), g(green), b(blue), a(alpha) {}
	
	bool operator == (Rgba8 const& compare) const 
	{
		return r == compare.r && g == compare.g && b == compare.b && a == compare.a;
	}

	bool operator != (Rgba8 const& compare) const
	{
		return r != compare.r || g != compare.g || b != compare.b || a != compare.a;
	}

public:
	static Rgba8	ConvertFloat4ToRgba8 (float const* colorFloat4);
	static float*	ConvertRgba8ToFloat4 (Rgba8 const& colorRgba8);
};

struct Rgba16
{
	unsigned short r = 65535;
	unsigned short g = 65535;
	unsigned short b = 65535;
	unsigned short a = 65535;

	Rgba16() {};
	Rgba16(unsigned short red, unsigned short green, unsigned short blue, unsigned short alpha = 65535)
		: r(red), g(green), b(blue), a(alpha) {}

	bool operator == (Rgba16 const& compare) const
	{
		return r == compare.r && g == compare.g && b == compare.b && a == compare.a;
	}

	bool operator != (Rgba16 const& compare) const
	{
		return r != compare.r || g != compare.g || b != compare.b || a != compare.a;
	}
};


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
		if (abs(c - 1.f) <= eps)
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