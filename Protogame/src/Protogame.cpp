#include "Protogame.hpp"

#include "mathpch.h"

#include "Engine/Window/Window.hpp"
#include "Engine/Graphics/RenderContext.hpp"
#include "Engine/Graphics/Vertex.hpp"
#include "Engine/Graphics/GpuBuffer.hpp"
#include "Engine/Graphics/Shader.hpp"
#include "Engine/Assets/AssetManager.hpp"
#include "Engine/Core/EngineSystem.hpp"

CREATE_APP(Protogame)

void Protogame::Startup()
{
	auto vs = g_assetManager.CreateShader(eShaderType::VERTEX_SHADER, L"FirstTriangleVS", "Assets/Shaders/VS_FirstTriangle.glsl", "main");
	auto ps = g_assetManager.CreateShader(eShaderType::PIXEL_SHADER, L"FirstTrianglePS", "Assets/Shaders/PS_FirstTriangle.glsl", "main");

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
	static Vertex vertices[] = {
		Vertex { Math::Vector3(-0.5f, -0.5f, 0.0f), Math::Vector2(0.f, 0.f) },
		Vertex { Math::Vector3(0.5f, -0.5f, 0.0f), Math::Vector2(0.f, 0.f) },
		Vertex { Math::Vector3(0.0f,  0.5f, 0.0f), Math::Vector2(0.f, 0.f) }
	};

	g_renderer.ClearScreen(Rgba8(125, 125, 255, 255));

	Graphics::RenderContext* context = g_renderer.CreateRenderContext();
	auto vbo = context->CreateVertexBuffer(sizeof(vertices), sizeof(Vertex));
	context->BindVertexBufferData(*vbo, vertices, 3, sizeof(Vertex));
	context->BindShader(*sh);
	context->DrawVertexBuffer(*vbo);

	delete context;
}

void Protogame::DrawFirstTriangle()
{
	
}
