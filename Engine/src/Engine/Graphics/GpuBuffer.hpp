#pragma once

#include "Engine/Graphics/RenderContext.hpp"

namespace Graphics
{
	struct BufferHandle
	{
		// GL
		GLuint* operator&() noexcept { return &handle; }
		operator GLuint() const { return handle; }
		GLuint handle = (GLuint)-1;
	};
}

namespace Graphics
{
	class VertexBuffer
	{
		friend class RenderContext;

	public:
		void CopyData(void const* data, size_t count, size_t stride);
		BufferHandle GetBufferHandle() const { return m_bufferHandle; }

	protected:
		VertexBuffer(size_t size, size_t stride, void const* data = nullptr);
		VertexBuffer(VertexBuffer const& copyFrom) = delete;
		virtual ~VertexBuffer();

	protected:
		size_t			m_bufferSize;
		size_t			m_bufferStride;
		BufferHandle	m_bufferHandle;
	};
}