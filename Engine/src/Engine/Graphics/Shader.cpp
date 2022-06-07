#include "Shader.hpp"

namespace Graphics
{
	std::map<std::wstring, Shader*> gShaderMaps;

	void RegisterShader(std::wstring const& name, Shader* shader)
	{
		gShaderMaps.emplace(std::make_pair(name, shader));
	}

	Shader* GetShader(std::wstring const& name)
	{
		return gShaderMaps[name];
	}

	void RemoveAllRegisteredShaders()
	{
		for (auto& p : gShaderMaps)
		{
			if (p.second)
			{
				delete p.second;
				p.second = nullptr;
			}
		}

		gShaderMaps.clear();
	}
}