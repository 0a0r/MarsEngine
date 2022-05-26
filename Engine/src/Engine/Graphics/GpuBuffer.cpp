#include "Engine/Graphics/GpuBuffer.hpp"

void Graphics::VertexBuffer::CopyData(void const* data, size_t count, size_t stride)
{
	// #ToDo: Fix the logic in here
}

Graphics::VertexBuffer::VertexBuffer(size_t size, size_t stride, void const* data)
	: m_bufferSize(size), m_bufferStride(stride)
{
	if (data != nullptr)
	{
		glGenBuffers(1, &m_bufferHandle);
	}
}

Graphics::VertexBuffer::~VertexBuffer()
{
}

