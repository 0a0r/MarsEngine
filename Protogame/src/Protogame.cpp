#include "Protogame.hpp"

#include "Engine/Window/Window.hpp"
#include "Engine/Graphics/RenderContext.hpp"
#include "Engine/Assets/AssetManager.hpp"

CREATE_APP(Protogame)

void Protogame::Startup()
{
	auto vs = EngineSystem::AssetManager::GetInstance().CreateShader(eShaderType::VERTEX_SHADER, L"FirstTriangleVS", "Assets/Shaders/VS_FirstTriangle.glsl", "main");
	auto ps = EngineSystem::AssetManager::GetInstance().CreateShader(eShaderType::PIXEL_SHADER, L"FirstTrianglePS", "Assets/Shaders/PS_FirstTriangle.glsl", "main");

	sh = new ShaderProgram(vs, ps);
}

void Protogame::Shutdown()
{
	delete sh;
	sh = nullptr;
}

void Protogame::Update()
{
}

void Protogame::RenderScene() const
{
	static float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	//Graphics::RenderContext* context = EngineSystem::Renderer::GetInstance().CreateRenderContext();

	//context->BindShader()

	//delete context;
}

void Protogame::DrawFirstTriangle()
{
	
}
