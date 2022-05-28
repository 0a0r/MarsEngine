#pragma once

#include "Engine/Graphics/Renderer.hpp"

struct ShaderProgram;

namespace Graphics
{
	class VertexBuffer; 

	class RenderContext
	{
		friend class EngineSystem::Renderer;

	public:
		virtual			~RenderContext() {}

		VertexBuffer*	CreateVertexBuffer(size_t size, size_t stride);
		void			BindVertexBufferData(VertexBuffer& vbo, void const* data, size_t count, size_t stride);
		void			BindShader(ShaderProgram const& shader);
		void			DrawVertexBuffer(VertexBuffer const& vbo);

	private:
		RenderContext() {}
	};
}