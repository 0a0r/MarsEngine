#include "GpuBuffer.hpp"

namespace Graphics
{
	void VertexBufferBase::CopyData(void const* data, size_t count, size_t stride)
	{
		pData = data;
		mStride = stride;
		mCount = count;
		mSize = count * stride;
	}
}