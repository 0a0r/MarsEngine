#pragma once

#include <map>
#include <vector>

#include "Engine/Core/EngineSystem.hpp"
#include "Engine/Core/EngineConfig.h"

#include "Rgba.hpp"

class WindowContext;

namespace Graphics
{
	enum eRendererType
	{
		GL,
		DX11,
		DX12,
		VULKAN
	};

	class Renderer;
	extern std::map<eRendererType, Renderer*> gRenderers;
	extern WindowContext* gWindow;
	extern Renderer* gRenderer;

	void Initialize();
	void Startup();
	void BeginFrame();
	void EndFrame();
	void Shutdown();

	class VertexBufferBase;
	struct RenderData
	{
		std::vector<VertexBufferBase*> vbs;
	};

	class Renderer
	{
	public:
		Renderer(WindowContext* wc);
		virtual ~Renderer() {}

	public:
		virtual void Startup() {}
		virtual void BeginFrame() {}
		virtual void EndFrame() {}
		virtual void Shutdown() {}
		virtual void Present() {}

	public:
		virtual void ClearScreen(Rgba8 const& clearColor) = 0;
		// Draw
		virtual void Draw(RenderData const& rd) = 0;

 		void SetWindowContext(WindowContext* wc) { mWindow = wc; }
		WindowContext* GetWindowContext() const { return mWindow; }

	protected:
		WindowContext*	mWindow = nullptr;
		unsigned int	mDisplayWidth;
		unsigned int	mDisplayHeight;
	};
	
	// typedef std::map<std::string, Renderer*>
	// extern
}