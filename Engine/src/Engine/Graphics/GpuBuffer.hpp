#pragma once

namespace Graphics
{
	class VertexBufferBase
	{
	public:
		VertexBufferBase() {}
		VertexBufferBase(VertexBufferBase const& copyFrom) = delete;
		virtual ~VertexBufferBase() {}

		size_t			GetSize() const { return mSize; }
		size_t			GetCount() const { return mCount; }
		size_t			GetStride() const { return mStride; }
		void const*		GetData() const { return pData; }

		virtual void	CopyData(void const* data, size_t count, size_t stride);

	protected:
		size_t			mSize	= 0;
		size_t			mStride = 0;
		size_t			mCount	= 0;
		void const*		pData	= nullptr;
	};
}