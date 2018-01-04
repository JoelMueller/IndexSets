#ifndef INDEX_SETS_H
#define INDEX_SETS_H

#include <vector>

namespace IndexSets
{
	template <typename T>
	struct ValueInserter
	{
		ValueInserter operator=(const std::vector<T> & rhs)
		{
			for (size_t i = 0; i < values.size(); ++i)
				*values[i] = rhs[i];
			return ValueInserter();
		}

		std::vector<T*> values;
	};

	template <typename T>
	struct Vector : std::vector<T>
	{
		Vector<T>(const std::vector<T> & v)	: std::vector<T>(v) {}
		Vector<T>(std::vector<T> && v)		: std::vector<T>(v) {}
		Vector<T>(int n)					: std::vector<T>(n) {}
		Vector<T>(ValueInserter<T> && vi)
		{
			std::vector<T>::reserve(vi.values.size());
			for (T * v : vi.values)
				std::vector<T>::push_back(*v);
		}

		T & operator[](int i)				{ return std::vector<T>::data()[i]; };
		const T & operator[](int i) const	{ return std::vector<T>::data()[i]; };

		ValueInserter<T> operator[](const std::vector<int> & indices)
		{
			ValueInserter<T> ret;
			ret.values.reserve(indices.size());
			auto data = std::vector<T>::data();
			for (auto i : indices)
				ret.values.push_back(data + i);
			return ret;
		}
	};
}

#endif