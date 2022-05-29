#pragma once

#include "Engine/Graphics/RenderContext.hpp"
#include <string>

class Shader;

enum eShaderType
{
	VERTEX_SHADER,
	// HULL_SHADER,
	GEOMETRY_SHADER,
	PIXEL_SHADER,
	// COMPUTE_SHADER,
	// RAYTRACING_SHADER
};

struct ShaderConfig
{
	std::wstring	shaderName;
	std::string		shaderPath;
	std::string		shaderEntryPoint;
	bool			isInternal;
};

struct ShaderProgram
{
	// GL: link both shaders using gl api
	// DX12: link both shaders in pso

	ShaderProgram(
		Shader const* vs,
		Shader const* ps = nullptr
	)
		: linkedVS(vs), linkedPS(ps)
	{
		Link();
	}

	void Link();

	Shader const* linkedVS = nullptr;
	Shader const* linkedPS = nullptr;

	// GL handle
	GLuint handle;
};

struct ShaderHandle
{
	// GL
	GLuint* operator&() noexcept { return &handle; }
	void operator=(const GLuint& other) noexcept { handle = other; }
	operator GLuint() const { return handle; }
	GLuint handle = (GLuint)-1;
};

class Shader
{
public:
	std::string		Code() const { return shaderSourceCode; }
	size_t			Size() const { return shaderSourceCode.size(); }
	ShaderHandle	GetHandle() const { return handle; }

public:
	Shader(ShaderConfig _config);
	virtual ~Shader();

protected:
	void			Create();
	void			Destroy();

	void			CheckError();
	virtual void	Compile() = 0;

protected:
	ShaderConfig config;
	ShaderHandle handle;

	std::string shaderSourceCode;
	eShaderType type;
};

class VertexShader : public Shader
{
public:
	VertexShader(ShaderConfig _config)
		: Shader(_config)
	{
		type = eShaderType::VERTEX_SHADER;
		Compile();
	}

	virtual void Compile() override;
};


class PixelShader : public Shader
{
public:
	PixelShader(ShaderConfig _config)
		: Shader(_config)
	{
		type = eShaderType::PIXEL_SHADER;
		Compile();
	}

	virtual void Compile() override;
};
