#include "AssetManager.hpp"

void EngineSystem::AssetManager::Shutdown()
{
	for (auto& s : loadedShader)
	{
		delete s.second;
		s.second = nullptr;
	}
	loadedShader.clear();
}

Shader* EngineSystem::AssetManager::CreateShader(eShaderType type, std::wstring const& name, const char* filePath, std::string entryPoint, bool isInternal)
{
	ShaderConfig config;
	config.shaderName = name;
	config.shaderPath = filePath;
	config.shaderEntryPoint = entryPoint;
	config.isInternal = isInternal;
	
	return CreateShader(type, config);
}

Shader* EngineSystem::AssetManager::CreateShader(eShaderType type, ShaderConfig const& shaderConfig)
{
	Shader* shader = nullptr;

	switch (type)
	{
	case eShaderType::VERTEX_SHADER:
		shader = new VertexShader(shaderConfig);
		break;
	case eShaderType::PIXEL_SHADER:
		shader = new PixelShader(shaderConfig);
		break;
	default:
		break;
	}

	loadedShader.emplace(std::make_pair(shaderConfig.shaderName, shader));
	return shader;
}

Shader* EngineSystem::AssetManager::GetShader(std::wstring const& name)
{
	if (loadedShader.find(name) != loadedShader.end())
	{
		return loadedShader[name];
	}
	return nullptr;
}
