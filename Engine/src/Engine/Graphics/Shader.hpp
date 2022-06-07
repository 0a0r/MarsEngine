#pragma once

#include <map>
#include <string>

namespace Graphics
{
	enum eShaderType
	{
		VERTEX_SHADER,
		// HULL_SHADER,
		GEOMETRY_SHADER,
		FRAGMENT_SHADER,
		// COMPUTE_SHADER,
		// RAYTRACING_SHADER
	};

	struct ShaderConfig
	{
		std::wstring	shaderName;
		std::string		shaderPath;
		std::string		shaderEntryPoint;
		std::string		shaderSourceCode;
		bool			isInternal;
	};

	class Shader;
	// Alias: GpuProgram (High-level GPU program)
	class ShaderProgram
	{
	public:
		// GL: link both shaders using gl api
		// DX12: link both shaders in pso
		ShaderProgram(
			Shader const* _vs,
			Shader const* _ps = nullptr
		)
			: vs(_vs), ps(_ps) {}
		virtual ~ShaderProgram() {}

		Shader const* vs = nullptr;
		Shader const* ps = nullptr;
	};

	class Shader
	{	
	public:
		std::string		GetCompiledCode() const { return mShaderCompiledCode; }
		size_t			GetCompiledCodeSize() const { return mShaderCompiledCode.size(); }

	public:
		Shader(ShaderConfig const& config) : mConfig(config) {}
		virtual			~Shader() {}

	protected:
		virtual void	CheckError() = 0;
		virtual void	Compile() = 0;

	protected:
		ShaderConfig	mConfig;
		std::string		mShaderCompiledCode;
		eShaderType		mType;
	};
}

namespace Graphics
{
	class Shader;
	extern std::map<std::wstring, Shader*> gShaderMaps;
	void	RegisterShader(std::wstring const& name, Shader* shader);
	Shader* GetShader(std::wstring const& name);
	void	RemoveAllRegisteredShaders();
}