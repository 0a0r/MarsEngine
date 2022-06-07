#include "GLRenderer.hpp"
#include "GLShader.hpp"
#include "GLBuffer.hpp"

#include "Engine/Window/Window.hpp"

namespace Graphics
{
	GLRenderer::GLRenderer(WindowContext* wc)
		: Renderer(wc)
	{
	}

	GLRenderer::~GLRenderer()
	{
	}

	void GLRenderer::Startup()
	{
		// GL 3.3
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		// For Mac OS X
		// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		glWindow = glfwCreateWindow(
			mDisplayWidth,
			mDisplayHeight,
			mWindow->GetWindowTitle().c_str(),
			NULL,
			NULL
		);

		// #ToDo: Add error handle logic
		if (glWindow == NULL)
		{
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(glWindow);

		// #ToDo: Add error handle logic
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			glfwTerminate();
			return;
		}

		glViewport(0, 0, mDisplayWidth, mDisplayHeight);

		// Using native Win32 window
		HWND glHWND = glfwGetWin32Window(glWindow);
		SetWindowLong(glHWND, GWL_STYLE, WS_VISIBLE);
		MoveWindow(glHWND, 0, 0, mDisplayWidth, mDisplayHeight, TRUE);
		SetParent(glHWND, static_cast<HWND>(mWindow->GetHWND()));
	}

	void GLRenderer::BeginFrame()
	{
	}

	void GLRenderer::EndFrame()
	{
		Sleep(1);
		Present();
	}

	void GLRenderer::Shutdown()
	{
		glfwTerminate();
	}

	void GLRenderer::Present()
	{
		glfwSwapBuffers(glWindow);
		glfwPollEvents();
	}

	void GLRenderer::ClearScreen(Rgba8 const& clearColor)
	{
		float* colFloat4 = Rgba8::ConvertRgba8ToFloat4(clearColor);

		glClearColor(colFloat4[0], colFloat4[1], colFloat4[2], colFloat4[3]);
		glClear(GL_COLOR_BUFFER_BIT);

		delete colFloat4;
	}

	void GLRenderer::Draw(RenderData const& rd)
	{
		GLRenderData const& glRD = static_cast<GLRenderData const&>(rd);

		// Bind shader
		GLShaderProgram const& glSP = static_cast<GLShaderProgram const&>(*glRD.shader);		
		glUseProgram(glSP.GetHandle());

		// Bind vertex arrays (temporary)
		auto const& vertexBuffers = glRD.vbs;
		std::vector<GLuint> vaoHandles;
		vaoHandles.resize(vertexBuffers.size(), 0);
		glGenVertexArrays(vertexBuffers.size(), vaoHandles.data());

		// #ToDo: Use better way
		for (int i = 0; i < vertexBuffers.size(); i++)
		{
			GLVertexBuffer const& glVB = static_cast<GLVertexBuffer const&>(*vertexBuffers[i]);
			size_t vbStride = glVB.GetStride();
			
			glBindVertexArray(vaoHandles[i]);
			glVB.BindVertexAttribute();

			// Draw command
			glDrawArrays(GL_TRIANGLES, 0, glVB.GetCount());
		}

		glDeleteVertexArrays(vertexBuffers.size(), vaoHandles.data());
	}
}