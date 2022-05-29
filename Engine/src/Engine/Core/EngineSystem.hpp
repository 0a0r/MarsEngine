#pragma once

namespace EngineSystem
{
	class Window;
	class Renderer;
	class AssetManager;
}

extern EngineSystem::Window& g_window;
extern EngineSystem::Renderer& g_renderer;
extern EngineSystem::AssetManager& g_assetManager;

namespace EngineSystem
{
	void InitializeAllEngineSystems();
	void StartupAllEngineSystems();
	void ShutdownAllEngineSystems();

	void BeginFrameAllEngineSystems();
	void EndFrameAllEngineSystems();
}

namespace EngineSystem
{
	template <typename T>
	class ISystem
	{
	public:
		static T& GetInstance() noexcept
		{
			static T instance;
			return instance;
		}

	public:
		virtual void Startup() {}
		virtual void BeginFrame() {}
		virtual void Update() {}
		virtual void Render() const {}
		virtual void EndFrame() {}
		virtual void Shutdown() {}

	protected:
		ISystem() {}
		virtual ~ISystem() noexcept {}
	};
}