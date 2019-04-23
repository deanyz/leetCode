#pragma once 

#include <iostream>
#include <vector>
 
namespace utl {
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
    //std::cout << "num1: " << &num1 << std::endl;
    //std::cout << "num2: " << &num2 << std::endl;
    if (&num1 == & num2)
        return ;
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
    // std::cout << "nums[lo]: " << nums[lo] << "; nums[last]: " << nums[last] << \
                //  "; nums[hi]: " << nums[hi] << "; nums[last++]: " << nums[last+1] << ";\n";
    // if (nums[hi] == -9243)
    //     std::cout << "A -9243: "; printVector(nums);
    if (nums[last] > nums[hi])
        swap(nums[last], nums[hi]);
    else if (last == hi -1)
        return hi;
    else
        swap(nums[++last], nums[hi]);
    // if (nums[hi] == -9243)
        // std::cout << "B -9243: "; printVector(nums);
    return last;
}

template <typename type>
int partitionNew(std::vector<type> & nums, int lo, int hi)
{
    if ( lo >= hi)
        return lo;
    type selVal = nums[hi];
    int pre = lo - 1;
    for (int i = lo; i < hi; i++) {
        if (nums[i] <= selVal){
            pre++;
            swap(nums[pre], nums[i]);
        }
    }
    swap(nums[pre+1], nums[hi]);

    return pre+1;
}

template <typename type>
void quickSort(std::vector<type> & nums, int lo, int hi)
{
   if (lo >= hi) return ;

   int pos = partitionNew(nums, lo, hi);

//    std::cout << "after partition: "; printVector(nums);
   quickSort(nums, lo, pos - 1);
   quickSort(nums, pos + 1, hi);
}

template <typename type>
void quickSort(std::vector<type> & nums)
{
   int hi = nums.size() - 1; 

   quickSort(nums, 0, hi);
}
}
