#include "GLBuffer.hpp"

#include "Engine/Graphics/Vertex.hpp"

namespace Graphics
{
	GLVertexBuffer::GLVertexBuffer()
		: VertexBufferBase()
	{
		glGenBuffers(1, &mHandle);
	}

	GLVertexBuffer::~GLVertexBuffer()
	{
		glDeleteBuffers(1, &mHandle);
	}

	void GLVertexBuffer::CopyData(void const* data, size_t count, size_t stride)
	{
		VertexBufferBase::CopyData(data, count, stride);

		glBindBuffer(GL_ARRAY_BUFFER, mHandle);
		glBufferData(GL_ARRAY_BUFFER, GetSize(), GetData(), GL_STATIC_DRAW);
	}

	void GLVertexBuffer::BindVertexAttribute() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, mHandle);

		// Position
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, GetStride(), (void*)offsetof(Vertex, position));
		glEnableVertexAttribArray(0);

		// UV
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, GetStride(), (void*)offsetof(Vertex, uv0));
		glEnableVertexAttribArray(1);
	}
}