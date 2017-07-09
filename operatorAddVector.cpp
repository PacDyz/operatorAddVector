// operatorAddVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <utility>

template<typename> struct is_std_vector :  std::false_type {};
template<typename T, typename A> struct is_std_vector<std::vector<T, A>> :  std::true_type {};
template <typename T>
std::enable_if_t<is_std_vector<std::decay_t<T>>::value, T>
operator+(T&& vec1, T&& vec2)
{
	for (int i = 0; i < vec2.size(); ++i)
		vec1.emplace_back(std::forward<int>(vec2.at(i)));
	return vec1;
}

int main()
{
	std::vector<int> vec1{ 1,2,3,4,5 };
	std::vector<int> vec2{ 2,3,4,5,6 };
	std::vector<int> vecResult;
	vecResult = std::move(vec1) + std::move(vec2);
	for (const auto& itr : vecResult)
		std::cout << itr << std::endl;
    return 0;
}

