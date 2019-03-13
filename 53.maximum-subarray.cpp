/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.89%)
 * Total Accepted:    474.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  /*   int maxSubArray(vector<int>& nums) {
        int maxSum = 0, thisSum = 0;
        bool bAllNegative = true;
        int maxNeg = 0;
        if (nums[0] < 0)
            maxNeg = nums[0];

        for ( int j = 0;  j < nums.size(); j++ )
        {
            if (nums[j] > 0) {
                bAllNegative = false;
            } else {
                if (maxNeg < nums[j])
                    maxNeg = nums[j];
            }

            thisSum += nums[j];
            if ( thisSum > maxSum )
                maxSum = thisSum;
            else if ( thisSum < 0)
                thisSum = 0;
        }

        if ( bAllNegative )
            return maxNeg;
        return maxSum;
    } */

    int maxSubArray(vector<int>& nums, int &begin, int &end)
    {
        if (begin == end)
            return nums[begin];
        
        int lbegin = begin, lend = begin + (end - begin)/2;
        int rbegin = lend + 1, rend = end;

        int lMax = maxSubArray(nums, lbegin, lend);
        int rMax = maxSubArray(nums, rbegin, rend);
        cout << "lMax[" << lbegin <<":"<< lend <<"] : " << lMax << "      rMax["<< rbegin << ":" << rend <<"] : " << rMax << endl;

        if (lend + 1 == rbegin && lMax > 0 && rMax > 0){
            begin = lbegin;
            end = rend;
            return lMax + rMax;
        }
        
        if (lMax > rMax){
            begin = lbegin;
            end = lend;
            return lMax;
        } 
        else {
            begin = rbegin;
            end = rend;
            return rMax;
        }
    }

    int maxSubArray(vector<int>& nums) 
    {

    }
};

int main()
{
    Solution sl;
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};

    int begin = 0;
    int end = nums.size() - 1;
    cout << sl.maxSubArray(nums, begin , end ) << endl;
    return 0;
}
