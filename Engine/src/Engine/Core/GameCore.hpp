#pragma once

#define WIN32_LEAN_AND_MEAN		// Always #define this before #including <windows.h>
#include <windows.h>

struct WindowConfig;

namespace GameCore
{
	class IGameApp
	{
	public:
		virtual void Startup() = 0;
		virtual void Shutdown() = 0;
		virtual void Update() = 0;
		virtual void Run() = 0;
		virtual void RenderScene() const = 0;
		virtual void RenderUI() const {};
	};
}

namespace GameCore
{
	extern IGameApp* g_App;
	void RunApp(IGameApp& app);
}

#define CREATE_APP(app_class) \
	int WINAPI WinMain(HINSTANCE applicationInstanceHandle, HINSTANCE, LPSTR commandLineString, int) \
	{ \
		if (GameCore::g_App) \
		{ \
			delete GameCore::g_App; \
		} \
		GameCore::g_App = new app_class(); \
		GameCore::RunApp(*GameCore::g_App); \
		delete GameCore::g_App; \
		GameCore::g_App = nullptr; \
		return 0; \
	}