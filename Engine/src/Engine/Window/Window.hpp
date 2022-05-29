#pragma once

#include "Engine/Core/EngineSystem.hpp"
#include "Engine/Core/EngineConfig.h"
#include <string>

#include "mathpch.h"

#define WIN32_LEAN_AND_MEAN		// Always #define this before #including <windows.h>
#include <windows.h>

namespace EngineSystem
{
	class Window : public ISystem<Window>
	{
		friend class ISystem<Window>;

	public:
		void Initialize(WindowConfig const& _config);
		void Startup() override;
		void BeginFrame() override;
		void Shutdown() override;

		int GetWindowWidth() const { return m_windowWidth; }
		int GetWindowHeight() const { return m_windowHeight; }
		std::string GetWindowTitle() const { return config.windowTitle; }
		void* GetHWND() const { return m_hwnd; }

	protected:
		void CreateOSWindow();
		void RunMessagePump();

	private:
		Window() {}
		~Window() {}

	private:
		WindowConfig	config;
		void*			m_hwnd = nullptr;
		void*			m_deviceContext = nullptr;

		int				m_windowWidth;
		int				m_windowHeight;
	};
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