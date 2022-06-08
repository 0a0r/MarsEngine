#pragma once

namespace Math
{
	template <typename TClass, typename TValue, size_t ... Indexes>
	class _swizzle
	{
	public:
		TValue data[sizeof...(Indexes)];

		TClass& operator= (TClass const& copyFrom)
		{
			size_t indexes[] = { Indexes... };
			for (size_t i = 0; i < sizeof...(Indexes); i++)
			{
				data[indexes[i]] = copyFrom[i];
			}
			return *(TClass*)this;
		}

		operator TClass() const
		{
			return TClass(data[Indexes]...);
		}
	};
}