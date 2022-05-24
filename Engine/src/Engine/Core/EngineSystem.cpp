#include "Engine/Core/EngineSystem.hpp"

#include "Engine/Window/Window.hpp"
#include "Engine/Graphics/Renderer.hpp"

void EngineSystem::InitializeAllEngineSystems()
{
	// #ToDo: User-defined
	// Window
	WindowConfig wc;
	wc.clientAspect = 2.0f;
	wc.windowTitle = "Default";
	Window::GetInstance().Initialize(wc);
	
	// Renderer (Must after Window initialization)
	RendererConfig rc;
	Renderer::GetInstance().Initialize(rc);
}

void EngineSystem::StartupAllEngineSystems()
{
	Window::GetInstance().Startup();
	Renderer::GetInstance().Startup();
}

void EngineSystem::ShutdownAllEngineSystems()
{
	Window::GetInstance().Shutdown();
	Renderer::GetInstance().Shutdown();
}

void EngineSystem::BeginFrameAllEngineSystems()
{
	Window::GetInstance().BeginFrame();
	Renderer::GetInstance().BeginFrame();
}

void EngineSystem::EndFrameAllEngineSystems()
{
	Window::GetInstance().EndFrame();
	Renderer::GetInstance().EndFrame();
}
