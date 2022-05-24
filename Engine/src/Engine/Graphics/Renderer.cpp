#include "Engine/Graphics/Renderer.hpp"
#include "Engine/Graphics/InternalGL.hpp"

#include "Engine/Window/Window.hpp"

void EngineSystem::Renderer::Initialize(RendererConfig const& _config)
{
	config = _config;
}

void EngineSystem::Renderer::Startup()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// For Mac OS X
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	displayWidth = Window::GetInstance().GetWindowWidth();
	displayHeight = Window::GetInstance().GetWindowHeight();

	glWindow = glfwCreateWindow(
		displayWidth,
		displayHeight,
		Window::GetInstance().GetWindowTitle().c_str(),
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

	glViewport(0, 0, displayWidth, displayHeight);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	HWND glHWND = glfwGetWin32Window(glWindow);
	SetWindowLong(glHWND, GWL_STYLE, WS_VISIBLE);
	MoveWindow(glHWND, 0, 0, displayWidth, displayHeight, TRUE);
	SetParent(glHWND, static_cast<HWND>(Window::GetInstance().GetHWND()));
}

void EngineSystem::Renderer::BeginFrame()
{
}

void EngineSystem::Renderer::EndFrame()
{
	Sleep(1);
	Present();
}

void EngineSystem::Renderer::Shutdown()
{
	glfwTerminate();
}

void EngineSystem::Renderer::Present()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(glWindow);
	glfwPollEvents();
}
