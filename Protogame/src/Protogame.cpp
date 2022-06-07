#include "Protogame.hpp"

#include "mathpch.h"

#include "Engine/Window/Window.hpp"
#include "Engine/Graphics/GLRenderer.hpp"
#include "Engine/Graphics/Vertex.hpp"
#include "Engine/Graphics/GLBuffer.hpp"
#include "Engine/Graphics/GLShader.hpp"
#include "Engine/Core/EngineSystem.hpp"

CREATE_APP(Protogame)

void Protogame::Startup()
{
	auto vs = Graphics::GLShader::Create(Graphics::eShaderType::VERTEX_SHADER, L"FirstTriangleVS", "Assets/Shaders/VS_FirstTriangle.glsl", "main");
	auto ps = Graphics::GLShader::Create(Graphics::eShaderType::FRAGMENT_SHADER, L"FirstTrianglePS", "Assets/Shaders/PS_FirstTriangle.glsl", "main");

	sh = new Graphics::GLShaderProgram(vs, ps);

	static Vertex vertices[] = {
		Vertex { Math::Vector3(-0.5f, -0.5f, 0.0f), Math::Vector2(0.f, 0.f) },
		Vertex { Math::Vector3(0.5f, -0.5f, 0.0f), Math::Vector2(0.f, 0.f) },
		Vertex { Math::Vector3(0.0f,  0.5f, 0.0f), Math::Vector2(0.f, 0.f) }
	};

	testVBO = new Graphics::GLVertexBuffer();
	testVBO->CopyData(vertices, 3, sizeof(Vertex));
}

void Protogame::Shutdown()
{
	delete sh;
	sh = nullptr;

	delete testVBO;
	testVBO = nullptr;
}

void Protogame::Update()
{
}

void Protogame::RenderScene() const
{
	Graphics::gRenderer->ClearScreen(Rgba8(125, 125, 255, 255));
	DrawFirstTriangle();
	// Graphics::gRenderer->Draw()
	//Graphics::RenderContext* context = g_renderer.CreateRenderContext();
	//auto vbo = context->CreateVertexBuffer(sizeof(vertices), sizeof(Vertex));
	//context->BindVertexBufferData(*vbo, vertices, 3, sizeof(Vertex));
	//context->BindShader(*sh);
	//context->DrawVertexBuffer(*vbo);

	//delete context;
}

void Protogame::DrawFirstTriangle() const
{
	Graphics::GLRenderData rData;
	rData.shader = sh;
	rData.vbs.emplace_back(testVBO);

	Graphics::gRenderer->Draw(rData);
}
