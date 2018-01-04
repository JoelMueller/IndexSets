#pragma once

#include <algorithm>
#include <vector>

namespace IndexSets
{

template <typename T>
struct VectorMask
{
    VectorMask & operator=(const std::vector<T> & rhs)
    {
        for (std::size_t i = 0; i < values.size(); ++i)
        {
            *values[i] = rhs[i];
        }
        return *this;
    }

    std::vector<T*> values;
};

template <typename T>
struct Vector : std::vector<T>
{
    using std::vector<T>::vector;

    Vector<T>(VectorMask<T> && vi)
    {
        std::vector<T>::reserve(vi.values.size());
        for (T * v : vi.values)
        {
            std::vector<T>::push_back(*v);
        }
    }

    using std::vector<T>::operator[];

    VectorMask<T> operator[](const std::vector<int> & indices)
    {
        VectorMask<T> ret;
        ret.values.reserve(indices.size());
        auto data = std::vector<T>::data();
        for (auto i : indices)
        {
            ret.values.push_back(data + i);
        }
        return ret;
    }
};

}
