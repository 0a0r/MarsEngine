#pragma once

#include <string>

struct WindowConfig
{
	float		clientAspect		= 2.0f;
	std::string windowTitle			= "Default";
};

struct RendererConfig
{
	// #ToDo: Add RHI settings (OpenGL, DX11, DX12, Vulkan)
};

#include "mathpch.h"

using namespace Math;