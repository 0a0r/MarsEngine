#include "Engine/Graphics/GpuBuffer.hpp"

void Graphics::VertexBuffer::CopyData(void const* data, size_t count, size_t stride)
{
	m_bufferData = data;
	m_bufferSize = count * stride;
}

void Graphics::VertexBuffer::Link() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferHandle);
	glBufferData(GL_ARRAY_BUFFER, m_bufferSize, m_bufferData, GL_STATIC_DRAW);
}

Graphics::VertexBuffer::VertexBuffer(size_t size, size_t stride)
	: m_bufferSize(size), m_bufferStride(stride)
{
	glGenBuffers(1, &m_bufferHandle);
}

Graphics::VertexBuffer::~VertexBuffer()
{
}

