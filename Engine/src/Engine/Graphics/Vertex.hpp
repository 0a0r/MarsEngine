#pragma once

#include "mathpch.h"
#include "Engine/Graphics/Rgba.hpp"

struct alignas(16) Vertex
{
	Math::Vector3 position; // P
	Rgba8 color; // C
	Math::Vector2 uvCoords; // U
};