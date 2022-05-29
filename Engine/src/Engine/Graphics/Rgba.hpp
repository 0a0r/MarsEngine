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