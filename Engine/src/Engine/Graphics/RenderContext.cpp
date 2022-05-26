#include "Engine/Graphics/RenderContext.hpp"
#include "Engine/Graphics/GpuBuffer.hpp"

// glBindBuffer(GL_ARRAY_BUFFER, handle);
Graphics::VertexBuffer* Graphics::RenderContext::CreateVertexBuffer(size_t size, size_t stride, void const* data)
{
	VertexBuffer* vb = new VertexBuffer(size, stride, data);
	return vb;
}

void Graphics::RenderContext::BindVertexBuffer(VertexBuffer const& vbo)
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo.GetBufferHandle());
}
