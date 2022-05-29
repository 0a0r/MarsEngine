#include "Engine/Graphics/Shader.hpp"
#include "Engine/Core/Utility.hpp"

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

void ShaderProgram::Link()
{
	handle = glCreateProgram();
	if (linkedVS) glAttachShader(handle, linkedVS->GetHandle());
	if (linkedPS) glAttachShader(handle, linkedPS->GetHandle());
	glLinkProgram(handle);

	// Error check
	/*
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if(!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			...
		}
	*/
}
