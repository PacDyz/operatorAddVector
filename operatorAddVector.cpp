// operatorAddVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
template<typename T>
std::vector<T> operator+( std::vector<T> vec1, std::vector<T> vec2)
{
	vec1.insert(vec1.end(), vec2.begin(), vec2.end());
	return vec1;
}
int main()
{
	std::vector<int> vec1{ 1,2,3,4,5 };
	std::vector<int> vec2{ 2,3,4,5,6 };
	std::vector<int> vecResult;
	vecResult = vec1 + vec2;
	for (const auto& itr : vecResult)
		std::cout << itr << std::endl;
    return 0;
}

