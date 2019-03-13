#pragma once 

#include <iostream>
#include <vector>
void printVector(std::vector<int> & nums) 
{
    for (auto & i : nums) {
        std::cout<<i << "  ";
    }
    std::cout << std::endl;
}