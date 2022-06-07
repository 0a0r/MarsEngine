#pragma once

#include "Engine/Core/EngineSystem.hpp"
#include "Engine/Core/EngineConfig.h"
#include <string>

#include "mathpch.h"

#define WIN32_LEAN_AND_MEAN		// Always #define this before #including <windows.h>
#include <windows.h>

class WindowContext
{
public:
	WindowContext() {}
	~WindowContext() {}

	void Initialize(WindowConfig const& _config);
	void Startup();
	void BeginFrame();
	void Shutdown();

	unsigned int GetWindowWidth() const { return mWindowWidth; }
	unsigned int GetWindowHeight() const { return mWindowHeight; }
	std::string GetWindowTitle() const { return mConfig.windowTitle; }
	void* GetHWND() const { return pHwnd; }

protected:
	void CreateOSWindow();
	void RunMessagePump();

private:
	WindowConfig	mConfig;
	void*			pHwnd = nullptr;
	void*			pDeviceContext = nullptr;

	unsigned int	mWindowWidth;
	unsigned int	mWindowHeight;
};

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