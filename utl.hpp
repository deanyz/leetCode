#pragma once 

#include <iostream>
#include <vector>

template <typename type>
void printVector(std::vector<type> & nums) 
{
    for (auto & i : nums) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}