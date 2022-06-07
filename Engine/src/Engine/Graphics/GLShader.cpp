#include "GLShader.hpp"

#include "Engine/Core/Utility.hpp"

namespace Graphics
{
	GLShaderProgram::GLShaderProgram(GLShader const* _glvs, GLShader const* _glps)
		: ShaderProgram(_glvs, _glps)
	{
		mHandle = glCreateProgram();

		if (_glvs && static_cast<GLVertexShader const*>(_glvs)) glAttachShader(mHandle, static_cast<GLVertexShader const*>(_glvs)->GetHandle());
		if (_glps && static_cast<GLFragmentShader const*>(_glps)) glAttachShader(mHandle, static_cast<GLFragmentShader const*>(_glps)->GetHandle());
		glLinkProgram(mHandle);

		// Error check
		/*
			glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
			if(!success) {
				glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
				...
			}
		*/
	}

	GLShaderProgram::~GLShaderProgram()
	{
		glDeleteProgram(mHandle);
	}

	GLShader::GLShader(ShaderConfig const& config)
		: Shader(config)
	{
		Initialize();
	}

	GLShader::~GLShader()
	{
		Destroy();
	}

	GLShader* GLShader::Create(
		eShaderType type, 
		std::wstring shaderName, 
		std::string shaderPath, 
		std::string shaderEntryPoint, 
		std::string shaderSourceCode, 
		bool isInternal)
	{
		ShaderConfig config;
		config.shaderName = shaderName;
		config.shaderPath = shaderPath;
		config.shaderEntryPoint = shaderEntryPoint;
		config.shaderSourceCode = shaderSourceCode;
		config.isInternal = isInternal;

		GLShader* shader = nullptr;
		switch (type)
		{
			case eShaderType::VERTEX_SHADER:
				shader = new GLVertexShader(config);
				break;
			case eShaderType::FRAGMENT_SHADER:
				shader = new GLFragmentShader(config);
				break;
			default:
				break;
		}

		return shader;
	}

	void GLShader::Initialize()
	{
		if (!mConfig.isInternal)
		{
			FileReadToString(mConfig.shaderSourceCode, mConfig.shaderPath);
		}
	}

	void GLShader::Destroy()
	{
		glDeleteShader(mHandle);
	}

	void GLShader::CheckError()
	{
		int success;
		std::string infoLog;

		glGetShaderiv(mHandle, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(mHandle, 512, NULL, const_cast<char*>(infoLog.c_str()));
		}
	}

	void GLVertexShader::Compile()
	{
		mHandle = glCreateShader(GL_VERTEX_SHADER);
		mShaderCompiledCode = mConfig.shaderSourceCode;
		const char* compiledCode = mConfig.shaderSourceCode.c_str();
		glShaderSource(mHandle, 1, &compiledCode, NULL);
		glCompileShader(mHandle);

		CheckError();
	}

	void GLFragmentShader::Compile()
	{
		mHandle = glCreateShader(GL_FRAGMENT_SHADER);
		mShaderCompiledCode = mConfig.shaderSourceCode;
		const char* compiledCode = mConfig.shaderSourceCode.c_str();
		glShaderSource(mHandle, 1, &compiledCode, NULL);
		glCompileShader(mHandle);

		CheckError();
	}
}