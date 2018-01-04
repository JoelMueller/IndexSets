#include "IndexSets.h"

#include <numeric>
#include <iostream>

int main(int argc, char** argv)
{
	IndexSets::Vector<int> vec(10);
	std::iota(vec.begin(), vec.end(), 0);
	vec[{1, 3, 4}] = { 11, 33, 44 };					// vec = { 0, 11, 2, 33, 44, 5, 6, 7, 8, 9 }
	IndexSets::Vector<int> vec2 = vec[{ 3, 5, 7 }];		// vec2 = { 33, 5, 7 }

	return 0;
}