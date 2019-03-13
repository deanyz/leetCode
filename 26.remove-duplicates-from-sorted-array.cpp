/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 * algorithms
 * Easy (39.77%)
 * Total Accepted:    535.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that each
 * element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums
 * being 1 and 2 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being modified to 0, 1, 2, 3, and 4 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
        int fst, secd;
        if (nums.size() < 2)
            return nums.size();
        
        for (int i = 0; i < nums.size() - 1; ) {
            fst = nums[i];
            secd = nums[i + 1];
            if ( fst == secd ) {
                for (int j = i + 1; j < nums.size() - 1; j++ ){
                    nums[j] = nums[j+1];
                }
                //nums.pop_back();
            } else {
                i++;
            }
        }

        return nums.size();
    }


};


void printVector(vector<int> & nums) 
{
    for (auto & i : nums) {
        cout<<i << "  ";
    }
    cout << endl;
}

int mergefoo(vector<int> & nums)
{
    int count = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1]){
            count++;
            printVector(nums);
        }
        else {
            nums[i - count] = nums[i];
            printVector(nums);
        }
    }
    return  nums.size() - count;
}

int main()
{
    Solution sl;
    vector<int> nums {1, 2, 2, 4, 5, 6};
    /*
    sl.removeDuplicates(nums);
    printVector(nums);

    nums = {1, 2, 2, 4, 5, 6};
    sl.removeDuplicates(nums);
    printVector(nums);
    */
    mergefoo(nums);
    return 0;
}

