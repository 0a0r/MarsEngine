#include "Engine/Graphics/RenderContext.hpp"
#include "Engine/Graphics/GpuBuffer.hpp"
#include "Engine/Graphics/Vertex.hpp"
#include "Engine/Graphics/Shader.hpp"

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

void Graphics::RenderContext::BindShader(ShaderProgram const& shader)
{
	glUseProgram(shader.handle);
}

void Graphics::RenderContext::DrawVertexBuffer(VertexBuffer const& vbo)
{
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);

	// Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vbo.GetStride(), (void*)offsetof(Vertex, position));
	
	// UV
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, vbo.GetStride(), (void*)offsetof(Vertex, uv0));

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

