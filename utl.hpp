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

template <typename type>
void swap(type &num1, type &num2)
{
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
}

template <typename type>
int partition(std::vector<type> & nums, int lo, int hi)
{
    if ( lo >= hi)
        return lo;
    type selVal = nums[hi];
    int last;
    last = hi - 1;
    while (lo < last) {
        if (nums[lo] > selVal && nums[last] < selVal) {
            swap(nums[lo], nums[last]);
        } 

        if (nums[lo] <= selVal)
            lo++;
        if (nums[last] >= selVal)
            last--;
    }

    if (nums[lo] > nums[hi])
        swap(nums[lo], nums[hi]);

    return last;
}

template <typename type>
void quickSort(std::vector<type> & nums, int lo, int hi)
{
   if (lo >= hi) return ;

   int pos = partition(nums, lo, hi);
   quickSort(nums, lo, pos - 1);
   quickSort(nums, pos + 1, hi);
}

template <typename type>
void quickSort(std::vector<type> & nums)
{
   int hi = nums.size() - 1; 

   quickSort(nums, 0, hi);
}
