#include "Engine/Core/EngineSystem.hpp"

#include "Engine/Assets/AssetManager.hpp"
#include "Engine/Window/Window.hpp"
#include "Engine/Graphics/Renderer.hpp"

EngineSystem::Window& g_window = EngineSystem::Window::GetInstance();
EngineSystem::Renderer& g_renderer = EngineSystem::Renderer::GetInstance();
EngineSystem::AssetManager& g_assetManager = EngineSystem::AssetManager::GetInstance();

void EngineSystem::InitializeAllEngineSystems()
{
	// #ToDo: User-defined
	
	// Window
	WindowConfig wc;
	wc.clientAspect = 2.0f;
	wc.windowTitle = "Default";
	g_window.Initialize(wc);
	
	// Renderer (Must after Window initialization)
	RendererConfig rc;
	g_renderer.Initialize(rc);
}

void EngineSystem::StartupAllEngineSystems()
{
	g_assetManager.Startup();
	g_window.Startup();
	g_renderer.Startup();
}

void EngineSystem::ShutdownAllEngineSystems()
{
	g_renderer.Shutdown();
	g_window.Shutdown();
	g_assetManager.Shutdown();
}

void EngineSystem::BeginFrameAllEngineSystems()
{
	g_window.BeginFrame();
	g_renderer.BeginFrame();
}

void EngineSystem::EndFrameAllEngineSystems()
{
	g_window.EndFrame();
	g_renderer.EndFrame();
}
