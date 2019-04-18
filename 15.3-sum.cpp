/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.76%)
 * Total Accepted:    522.7K
 * Total Submissions: 2.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * â  [-1, 0, 1],
 * â  [-1, -1, 2]
 * ]
 * 
 * 
 */

/* #include "utl.hpp"
using namespace std */;

class Solution {
public:
    vector<int> genSortedVector(int x, int y, int z)
    {
        vector<int> result;
        if (x <= y && x <= z) {
            result.push_back(x);
            if (y <= z) {
                result.push_back(y);
                result.push_back(z);
            } else {
                result.push_back(z);
                result.push_back(y);
            }
        } else if (y <= x && y <= z) {
            result.push_back(y);
            if (x <= z) {
                result.push_back(x);
                result.push_back(z);
            } else {
                result.push_back(z);
                result.push_back(x);
            }
        } else {
            result.push_back(z);
            if (x <= y) {
                result.push_back(x);
                result.push_back(y);
            } else {
                result.push_back(y);
                result.push_back(x);
            }
        }
        return result;
    }

    bool inVector(vector<vector<int>> &src, vector<int> target)
    {
        bool isIn = false;
        for (auto &elem : src) {
            if (target[0] == elem[0] && target[1] == elem[1] && target[2] == elem[2])
                return true;
        }
        return isIn;
    }

    /*  时间复杂度不满足
  vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        int length = nums.size();
        for (int x = 0; x < length - 2; x++)
            for (int y = x + 1; y < length - 1; y++)
                for (int z = y + 1; z < length; z++) {
                    if (0 == (nums[x] + nums[y] + nums[z])) {
                        tmp = genSortedVector(nums[x], nums[y], nums[z]);
                        if (!inVector(result, tmp)) {
                            result.push_back(tmp);
                        }
                    }
                }

        return result;
    } */

    vector<int> sortedInsert(vector<int> & nums, int num, bool ascend = true, bool ignoreRepeat = false)
    {
        auto it = nums.begin();
        for (; it != nums.end(); it++)
        {
            if (ignoreRepeat && num == *it)
                break;

            if (ascend ? (num < *it):(num > *it))
            {
                nums.insert(it, num);
                break;
            }
        }

        if (it == nums.end())
            nums.push_back(num);

        return nums;
    }

    vector<vector<int> > threeSum(vector<int> &nums)
    {
        vector<vector<int> > result;
        vector<int> positiveArray;
        vector<int> negativeArray;
        vector<int> zeroArray;
        for (auto &i : nums) {
            if (i > 0) {
                sortedInsert(positiveArray, i);
            } else if (i < 0) {
                sortedInsert(negativeArray, i, false);
            } else {
                sortedInsert(zeroArray, i);
            }
        }

    /*     std::cout << "positiveArray: ";
        printVector(positiveArray);
        std::cout << "negativeArray: ";
        printVector(negativeArray);
        std::cout << "zeroArray: ";
        printVector(zeroArray) */;

        // =0, >0, <0
        for (auto &x : zeroArray) {
           for (auto &y : positiveArray) {
               for (auto &z : negativeArray) {
                   if ( y + z < 0) {
                       break;
                   } else if ( 0 == y + z) {
                       //result.emplace_back(vector<int>{z, x, y});
                       auto tmp = genSortedVector(z, x, y);
                       if (!inVector(result, tmp)) {
                           result.push_back(tmp);
                       }
                   }
               }
           }
        }

        // >0, <0, <0
        for (auto it_x = positiveArray.cbegin(); it_x != positiveArray.cend(); it_x++) {
            for (auto it_y = negativeArray.cbegin(); it_y != negativeArray.cend() - 1; it_y++) {
                for (auto it_z = it_y + 1; it_z != negativeArray.cend(); it_z++) {
                    if ( 0 == (*it_x + *it_y + *it_z)) {
                        //result.emplace_back(vector<int>{*it_z, *it_y, *it_x});
                        auto tmp = genSortedVector(*it_x, *it_y, *it_z);
                        if (!inVector(result, tmp)) {
                            result.push_back(tmp);
                        }
                    }
                }
            }
        }

        // <0, >0, >0
        for (auto it_x = negativeArray.cbegin(); it_x != negativeArray.cend(); it_x++) {
            for (auto it_y = positiveArray.cbegin(); it_y != positiveArray.cend() - 1; it_y++) {
                for (auto it_z = it_y + 1; it_z != positiveArray.cend(); it_z++) {
                    if ( 0 == (*it_x + *it_y + *it_z)) {
                        //result.emplace_back(vector<int>{*it_x, *it_y, *it_z});
                        auto tmp = genSortedVector(*it_x, *it_y, *it_z);
                        if (!inVector(result, tmp)) {
                            result.push_back(tmp);
                        }
                    }
                }
            }
        }
        return result;
    }
};

/* int main()
{
    Solution sl;
    vector<int> array{-1, 0, 1, 2, -1, 1, -4};
    printVector(array);
    //std::cout << array << std::endl;
    auto result = sl.threeSum(array);
    for (auto & i : result) {
        printVector(i);
    }

    return 0;
} */
