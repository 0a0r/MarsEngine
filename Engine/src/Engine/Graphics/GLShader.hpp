#pragma once

#include "Shader.hpp"
#include "GLInternal.hpp"

namespace Graphics
{
	class GLShader;
	class GLShaderProgram : public ShaderProgram
	{
	public:
		GLShaderProgram(
			GLShader const* _glvs,
			GLShader const* _glps = nullptr
		);
		virtual ~GLShaderProgram();

		GLuint GetHandle() const { return mHandle; }

	protected:
		GLuint mHandle;
	};

	class GLVertexShader;
	class GLFragmentShader;
	class GLShader : public Shader
	{
	public:
		static GLShader*	Create(
			eShaderType		type,
			std::wstring	shaderName,
			std::string		shaderPath,
			std::string		shaderEntryPoint,
			std::string		shaderSourceCode = "",
			bool			isInternal = false
		);

		GLuint GetHandle() const { return mHandle; }
	
	protected:
		void Initialize();
		void Destroy();
		void CheckError() override;
		virtual void Compile() = 0;

	public:
		GLShader(ShaderConfig const& config);
		virtual ~GLShader();

	protected:
		GLuint mHandle;
	};

	class GLVertexShader : public GLShader
	{
	public:
		GLVertexShader(ShaderConfig const& config)
			: GLShader(config)
		{
			mType = eShaderType::VERTEX_SHADER;
			Compile();
		}

		void Compile() override;
	};

	class GLFragmentShader : public GLShader
	{
	public:
		GLFragmentShader(ShaderConfig const& config)
			: GLShader(config)
		{
			mType = eShaderType::FRAGMENT_SHADER;
			Compile();
		}

		void Compile() override;
	};
}