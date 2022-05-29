#include "Engine/Graphics/Renderer.hpp"
#include "Engine/Graphics/RenderContext.hpp"
#include "Engine/Graphics/Rgba.hpp"
#include "Engine/Window/Window.hpp"

void EngineSystem::Renderer::Initialize(RendererConfig const& _config)
{
	config = _config;
}

void EngineSystem::Renderer::Startup()
{
	// GL 3.3
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

	// Using native Win32 window
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
	glfwSwapBuffers(glWindow);
	glfwPollEvents();
}

void EngineSystem::Renderer::ClearScreen(Rgba8 const& clearColor)
{
	float* colFloat4 = Rgba8::ConvertRgba8ToFloat4(clearColor);

	glClearColor(colFloat4[0], colFloat4[1], colFloat4[2], colFloat4[3]);
	glClear(GL_COLOR_BUFFER_BIT);

	delete colFloat4;
}

Graphics::RenderContext* EngineSystem::Renderer::CreateRenderContext()
{
	return new Graphics::RenderContext();
}
