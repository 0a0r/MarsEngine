#pragma once

#include "Engine/Graphics/RenderContext.hpp"
#include <string>

struct ShaderConfig
{
	std::wstring	shaderName;
	std::string		shaderPath;
	std::string		shaderEntryPoint;
	bool			isInternal;
};

enum eShaderType
{
	VERTEX_SHADER,
	// HULL_SHADER,
	GEOMETRY_SHADER,
	PIXEL_SHADER,
	// COMPUTE_SHADER,
	// RAYTRACING_SHADER
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
	std::string		Code() const;
	size_t			Size() const;

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
