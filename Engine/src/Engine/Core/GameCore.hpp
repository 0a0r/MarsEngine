#pragma once

struct WindowConfig;

namespace GameCore
{
	class IGameApp
	{
	public:
		virtual void Startup() = 0;
		virtual void Shutdown() = 0;
		virtual void BeginFrame();
		virtual void Update() = 0;
		virtual void RenderScene() const = 0;
		virtual void RenderUI() const {};
		virtual void EndFrame();

		void HandleQuitRequest();
	
	public:
		virtual void Run();

	protected:
		bool m_quitFlag = false;
	};
}

namespace GameCore
{
	extern IGameApp* g_App;
	void RunApp(IGameApp& app);
}