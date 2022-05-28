#include "Engine/Graphics/RenderContext.hpp"
#include "Engine/Graphics/GpuBuffer.hpp"

// glBindBuffer(GL_ARRAY_BUFFER, handle);
Graphics::VertexBuffer* Graphics::RenderContext::CreateVertexBuffer(size_t size, size_t stride)
{
	VertexBuffer* vb = new VertexBuffer(size, stride);
	return vb;
}

void Graphics::RenderContext::BindVertexBufferData(VertexBuffer& vbo, void const* data, size_t count, size_t stride)
{
	vbo.CopyData(data, count, stride);
}
