#include "Engine/Graphics/Shader.hpp"
#include "Engine/Core/FileUtils.hpp"

Shader::Shader(ShaderConfig _config)
	: config(_config)
{
	Create();
}

Shader::~Shader()
{
	Destroy();
}

void Shader::Create()
{
	FileReadToString(shaderSourceCode, config.shaderPath);

}

void Shader::Destroy()
{
	glDeleteShader(handle);
}

void Shader::CheckError()
{
	int success;
	std::string infoLog;

	glGetShaderiv(handle, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(handle, 512, NULL, const_cast<char*>(infoLog.c_str()));
	}
}

std::string Shader::Code() const
{
	return shaderSourceCode;
}

size_t Shader::Size() const
{
	return shaderSourceCode.size();
}

void VertexShader::Compile()
{
	handle = glCreateShader(GL_VERTEX_SHADER);
	const char* code = shaderSourceCode.c_str();
	glShaderSource(handle, 1, &code, NULL);
	glCompileShader(handle);

	CheckError();
}

void PixelShader::Compile()
{
	handle = glCreateShader(GL_FRAGMENT_SHADER);
	const char* code = shaderSourceCode.c_str();
	glShaderSource(handle, 1, &code, NULL);
	glCompileShader(handle);

	CheckError();
}
