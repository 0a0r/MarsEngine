#include "EngineSystem.hpp"

#include "Engine/Thread/JobSystem.hpp"
#include "Engine/Window/Window.hpp"
#include "Engine/Graphics/Renderer.hpp"

void EngineSystem::InitializeAllEngineSystems()
{
	JobSystem::Initialize();
	Graphics::Initialize();
}

void EngineSystem::StartupAllEngineSystems()
{
	Graphics::Startup();
}

void EngineSystem::ShutdownAllEngineSystems()
{
	Graphics::Shutdown();
	JobSystem::Destroy();
}

void EngineSystem::BeginFrameAllEngineSystems()
{
	Graphics::BeginFrame();
}

void EngineSystem::EndFrameAllEngineSystems()
{
	Graphics::EndFrame();
}
