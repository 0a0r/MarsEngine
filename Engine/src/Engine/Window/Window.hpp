#pragma once

#include "Engine/Core/EngineSystem.hpp"
#include "Engine/Core/EngineConfig.h"
#include <string>

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
	};
}

