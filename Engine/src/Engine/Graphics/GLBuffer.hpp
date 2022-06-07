#pragma once

#include "GpuBuffer.hpp"
#include "GLInternal.hpp"

namespace Graphics
{
	class GLVertexBuffer : public VertexBufferBase
	{
	public:
		GLVertexBuffer();
		GLVertexBuffer(GLVertexBuffer const& copyFrom) = delete;
		virtual ~GLVertexBuffer();

		void CopyData(void const* data, size_t count, size_t stride) override;
		void BindVertexAttribute() const;

		// Buffer handle
		GLuint GetHandle() const { return mHandle; }

	protected:
		GLuint mHandle;
	};
}