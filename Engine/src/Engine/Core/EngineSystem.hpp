#pragma once

namespace EngineSystem
{
	void InitializeAllEngineSystems();
	void StartupAllEngineSystems();
	void ShutdownAllEngineSystems();
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