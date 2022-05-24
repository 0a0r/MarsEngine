#pragma once

#include "Engine/Core/EngineSystem.hpp"
#include "Engine/Core/EngineConfig.h"

namespace EngineSystem
{
	class Renderer : public ISystem<Renderer>
	{
		friend class ISystem<Renderer>;

	public:
		void Initialize(RendererConfig const& _config);
		void Startup() override;
		void BeginFrame() override;
		void Shutdown() override;
		
	private:
		RendererConfig config;
	};
}