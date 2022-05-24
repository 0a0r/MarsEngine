#pragma once

#include "Engine/Graphics/Renderer.hpp"

class RenderContext
{
	friend class EngineSystem::Renderer;

public:
	virtual ~RenderContext() {}

private:
	RenderContext() {}
};