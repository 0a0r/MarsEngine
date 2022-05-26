#pragma once

#include "Engine/Graphics/Renderer.hpp"

namespace Graphics
{
	class VertexBuffer; 

	class RenderContext
	{
		friend class EngineSystem::Renderer;

	public:
		virtual			~RenderContext() {}

		VertexBuffer*	CreateVertexBuffer(size_t size, size_t stride, void const* data);
		void			BindVertexBuffer(VertexBuffer const& vbo);

	private:
		RenderContext() {}
	};
}