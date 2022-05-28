#pragma once

#include "Engine/Core/EngineSystem.hpp"
#include "Engine/Core/EngineConfig.h"

// #ToDo: Fix the logic in here
#include "Engine/Graphics/InternalGL.hpp"

struct Rgba8;

namespace Graphics
{
	class RenderContext;
}

namespace EngineSystem
{
	class Renderer : public ISystem<Renderer>
	{
		friend class ISystem<Renderer>;

	public:
		void Initialize(RendererConfig const& _config);
		void Startup() override;
		void BeginFrame() override;
		void EndFrame() override;
		void Shutdown() override;

	public:
		void Present();

	public:
		void ClearScreen(Rgba8 const& clearColor);
		
	private:
		RendererConfig config;
		int displayWidth;
		int displayHeight;

		GLFWwindow* glWindow = nullptr;
	};
}