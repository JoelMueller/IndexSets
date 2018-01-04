#include <iostream>
#include <numeric>
#include <string>

#include "IndexSets.h"

int main(int argc, char** argv)
{
    auto print = [] (std::string name, const auto & vec) {
        std::cout << name << " = [";
        for (std::size_t i = 0; i < vec.size() - 1; ++i)
        {
            std::cout << vec[i] << ", ";
        }
        std::cout << vec.back() << "]\n";
    };

    IndexSets::Vector<int> vec(10);
    std::iota(vec.begin(), vec.end(), 0);
    print("vec", vec);

    vec[{1, 3, 4}] = { 11, 33, 44 };
    print("vec", vec);

    IndexSets::Vector<int> vec2 = vec[{ 3, 5, 7 }];
    print("vec2", vec2);

    return 0;
}