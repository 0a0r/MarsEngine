#pragma once

#include "Engine/Core/EngineSystem.hpp"

#include "Engine/Graphics/Shader.hpp"

#include <string>
#include <map>

class Shader;
struct ShaderConfig;

namespace EngineSystem
{
	class AssetManager : public ISystem<AssetManager>
	{
		friend class ISystem<AssetManager>;

	public:
		void Shutdown() override;

	public:
		Shader* CreateShader(eShaderType type, std::wstring const& name, const char* filePath, std::string entryPoint, bool isInternal = false);
		Shader* CreateShader(eShaderType type, ShaderConfig const& shaderConfig);
		Shader* GetShader(std::wstring const& name);

	protected:
		// #ToDo: Use GUID in here
		std::map<std::wstring, Shader*> loadedShader;
	};
}