#include "GameCore.hpp"

#include "Engine/Window/Window.hpp"

namespace GameCore
{
	IGameApp* g_App;

	void IGameApp::BeginFrame()
	{
		EngineSystem::BeginFrameAllEngineSystems();
	}

	void IGameApp::EndFrame()
	{
		EngineSystem::EndFrameAllEngineSystems();
	}

	void IGameApp::HandleQuitRequest()
	{
		m_quitFlag = true;
	}

	void IGameApp::Run()
	{
		while (!m_quitFlag)
		{
			BeginFrame();
			Update();
			RenderScene();
			RenderUI();
			EndFrame();
		}
	}
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