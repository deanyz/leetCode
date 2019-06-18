/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */


#ifdef  TEST

#include "gtest/gtest.h"
#include "utl.hpp"
#include <algorithm>
using namespace std;

#endif

class Solution {
public:
    int absoluteCompare(int a, int b) 
    {
        a = a > 0 ? a : -a; 
        b = b > 0 ? b : -b;

        return (a - b);
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int result = 0xffffffff >> 1;
        int last = 0xffffffff >> 1;
        for (int x = 0; x < static_cast<int>(nums.size()) - 2; x++) {
            int y = x + 1;
            int z = nums.size() - 1;
            
            while ( y < z ) {
                int ret = nums[x] + nums[y] + nums[z] - target;

                if ( absoluteCompare(ret, last) < 0 ) {
                    last = ret;
                    result = last + target;
                }

                if ( ret > 0) {
                    z--;
                } else if ( ret < 0) {
                    y++; 
                } else if ( ret == 0 ) {
                    return target;
                }
            }
        }

        return result;
    }
};


#ifdef TEST
//int main()
//{
//    Solution sl;
//    std::vector<int> nums { -1, 2, 1, 4 };
//    std::cout <<  sl.threeSumClosest(nums, 1) << std::endl;
//
//    return 0;
//}

TEST(ThreeSumClosest, Normal) {
    Solution sl;

    std::vector<int> nums1 { -1, 2, 1, 4 };
    EXPECT_EQ (2, sl.threeSumClosest(nums1, 1));

    std::vector<int> nums2 { -4, 1,  -5, -10,  -1, 3, 4, 6, 4, 7 };
    EXPECT_EQ (9 , sl.threeSumClosest(nums2, 9));

    //std::vector<int> nums2 { -4, 1,  -5, -10,  -1, 3, 4, 6, 4, 7 };
    EXPECT_EQ (5 , sl.threeSumClosest(nums2, 5));

    std::vector<int> nums3 { 0, 0, 0 };
    EXPECT_EQ (0 , sl.threeSumClosest(nums3, 1));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#endif
