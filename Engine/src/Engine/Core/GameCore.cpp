#include "Engine/Core/GameCore.hpp"
#include "Engine/Core/EngineConfig.h"

#include "Engine/Window/Window.hpp"

namespace GameCore
{
	IGameApp* g_App;
}

void GameCore::RunApp(IGameApp& app)
{
	EngineSystem::InitializeAllEngineSystems();
	
	EngineSystem::StartupAllEngineSystems();
	app.Startup();

	app.Run();

	app.Shutdown();
	EngineSystem::ShutdownAllEngineSystems();
}