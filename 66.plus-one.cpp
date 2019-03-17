/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.78%)
 * Total Accepted:    361.2K
 * Total Submissions: 885.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */

#include <iostream>
#include <vector>
#include "utl.hpp"
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto r_it = digits.rbegin();
        (*r_it)++;

        while (*r_it > 9) {
            *r_it = 0;
            r_it++;
            if (r_it != digits.rend())
                (*r_it)++;
            else {
                digits.insert(digits.begin(), 1);
                break;
            }
        }
        
        return digits;
    }
};


int main()
{
    Solution sl;
    vector<int> nums {9};

    printVector(nums);
    auto x = sl.plusOne(nums);
    //printVector(nums);
    printVector(x);
    // printVector(sl.plusOne(nums));


    return 0;
}
