/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.98%)
 * Total Accepted:    412.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
/* #include "utl.hpp"
using namespace std; */

class Solution {
public:
    vector<int> mergeArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        auto it_nums1 = nums1.cbegin();
        auto it_nums2 = nums2.cbegin();
        while (it_nums1 != nums1.cend() && it_nums2 != nums2.cend()) {
            if (*it_nums1 < *it_nums2) {
                result.push_back(*it_nums1);
                it_nums1++;
            } else {
                result.push_back(*it_nums2);
                it_nums2++;
            }
        }

        while (it_nums1 != nums1.cend()) {
            result.push_back(*it_nums1);
            it_nums1++;
        }

        while (it_nums2 != nums2.cend()) {
            result.push_back(*it_nums2);
            it_nums2++;
        }
        
        return result;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result = mergeArray(nums1, nums2);
        int length = 0;
        double ret;
        length = result.size();
        if (length % 2 == 0) {
            ret = (result[length/2 - 1] + result[length/2])/2.0;
        } else {
            ret = result[length/2];
        }

        return ret;
    }
};

/* int main()
{
    vector<int> nums1 {1, 3};
    vector<int> nums2 {2};
    Solution sl;
    std::cout << sl.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;
} */
