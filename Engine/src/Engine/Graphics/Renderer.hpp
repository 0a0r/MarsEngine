#pragma once

#include "Engine/Core/EngineSystem.hpp"
#include "Engine/Core/EngineConfig.h"

struct GLFWwindow;

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

		void Present();
		
	private:
		RendererConfig config;
		int displayWidth;
		int displayHeight;

		GLFWwindow* glWindow = nullptr;
	};
}