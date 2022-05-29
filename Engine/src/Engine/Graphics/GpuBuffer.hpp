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
		void			CopyData(void const* data, size_t count, size_t stride);
		BufferHandle	GetBufferHandle() const { return m_bufferHandle; }
		size_t			GetStride() const { return m_bufferStride; }
		void			Link() const;

	protected:
		VertexBuffer(size_t size, size_t stride);
		VertexBuffer(VertexBuffer const& copyFrom) = delete;
		virtual ~VertexBuffer();

	protected:
		size_t			m_bufferSize;
		size_t			m_bufferStride;
		BufferHandle	m_bufferHandle;

		void const*		m_bufferData = nullptr;
	};
}