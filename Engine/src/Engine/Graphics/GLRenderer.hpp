#pragma once

#include "Engine/Graphics/Renderer.hpp"

#include "GLInternal.hpp"

class WindowContext;

namespace Graphics
{
	class ShaderProgram;
	struct GLRenderData : public RenderData
	{
		ShaderProgram* shader = nullptr;
	};

	class GLRenderer : public Renderer
	{
	public:
		GLRenderer(WindowContext* wc);
		~GLRenderer();

	public:
		void Startup() override;
		void BeginFrame() override;
		void EndFrame() override;
		void Shutdown() override;
		void Present() override;

	public:
		void ClearScreen(Rgba8 const& clearColor) override;
		void Draw(RenderData const& rd) override;

	private:
		GLFWwindow* glWindow = nullptr;
	};
}