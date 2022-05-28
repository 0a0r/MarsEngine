#include "Engine/Graphics/GpuBuffer.hpp"

void Graphics::VertexBuffer::CopyData(void const* data, size_t count, size_t stride)
{
	glGenBuffers(1, &m_bufferHandle);
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferHandle);
	glBufferData(GL_ARRAY_BUFFER, count * stride, data, GL_STATIC_DRAW);
}

Graphics::VertexBuffer::VertexBuffer(size_t size, size_t stride)
	: m_bufferSize(size), m_bufferStride(stride)
{
}

Graphics::VertexBuffer::~VertexBuffer()
{
}

