#pragma once

#include <mutex>

// Fixed-size ring buffer (thread-safe)
template <typename T, size_t Cap>
class FixedRingBuffer
{
public:
	FixedRingBuffer() {}
	virtual ~FixedRingBuffer() {}

	inline bool push_back(T const& val);
	inline bool pop_front(T& val);

	size_t Size() const
	{
		return (mTail - mHead + Cap) % Cap;
	}

protected:
	T			mData[Cap];
	size_t		mHead = 0;
	size_t		mTail = 0;
	std::mutex	mMutex;
};

template<typename T, size_t Cap>
inline bool FixedRingBuffer<T, Cap>::push_back(T const& val)
{
	bool result = false;
	std::unique_lock<std::mutex> lock(mMutex);

	size_t next = (mTail + 1) % Cap;
	if (next != mHead)
	{
		mData[mTail] = val;
		mTail = next;
		result = true;
	}

	return result;
}

template<typename T, size_t Cap>
inline bool FixedRingBuffer<T, Cap>::pop_front(T& val)
{
	bool result = false;
	std::unique_lock<std::mutex> lock(mMutex);

	if (mHead != mTail)
	{
		val = mData[mHead];
		mHead = (mHead + 1) % Cap;
		result = true;
	}

	return result;
}
