#include "Engine/Graphics/Renderer.hpp"
#include "Engine/Graphics/Rgba.hpp"
#include "Engine/Window/Window.hpp"

#include "GLRenderer.hpp"
#include "GLShader.hpp"

namespace Graphics
{
	std::map<eRendererType, Renderer*>	gRenderers;
	WindowContext*						gWindow = nullptr;
	Renderer*							gRenderer = nullptr;
}

namespace Graphics
{
	void Initialize()
	{
		// Initialize window
		WindowConfig winContext;
		winContext.clientAspect = 2.0f;
		winContext.windowTitle = "Default";
		gWindow = new WindowContext();
		gWindow->Initialize(winContext);

		// Initialize GL renderer
		gRenderers.emplace(std::make_pair(eRendererType::GL3, new GLRenderer(gWindow)));
	
		// #ToDo: Initialize DX11 renderer

		// #ToDo: Initialize DX12 renderer
		
		gRenderer = gRenderers[eRendererType::GL3];
	}

	void Graphics::Startup()
	{
		gWindow->Startup();
		gRenderer->Startup();
	}

	void Graphics::BeginFrame()
	{
		gWindow->BeginFrame();
		gRenderer->BeginFrame();
	}

	void Graphics::EndFrame()
	{
		// gWindow->EndFrame();
		gRenderer->EndFrame();
	}

	void Graphics::Shutdown()
	{
		RemoveAllRegisteredShaders();
		gRenderer->Shutdown();
		gWindow->Shutdown();
	}
}

namespace Graphics
{
	Renderer::Renderer(WindowContext* wc)
		: mWindow(wc)
	{
		mDisplayWidth = mWindow->GetWindowWidth();
		mDisplayHeight = mWindow->GetWindowHeight();
	}
}
