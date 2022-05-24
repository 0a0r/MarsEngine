#include "Engine/Core/EngineSystem.hpp"

#include "Engine/Window/Window.hpp"

void EngineSystem::InitializeAllEngineSystems()
{
	// #ToDo: User-defined
	// Window
	WindowConfig wc;
	wc.clientAspect = 2.0f;
	wc.windowTitle = "Default";
	Window::GetInstance().Initialize(wc);
	
	// Renderer
	// InputSystem
}

void EngineSystem::StartupAllEngineSystems()
{
	Window::GetInstance().Startup();
}

void EngineSystem::ShutdownAllEngineSystems()
{
	Window::GetInstance().Shutdown();
}