/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
#ifdef TEST
#include "utl.hpp"
#include "gtest/gtest.h"
#include <algorithm>
using namespace std;
#endif

class Solution {
public:
    int absoluteCompare(int a, int b) {
        a = a > 0 ? a : -a; 
        b = b > 0 ? b : -b;

        return (a - b);
    }

    bool hasTriplet(vector<vector<int>> &set, vector<int> &trip) {
        for (auto &vec : set) {
            if (vec.size() == trip.size() && trip.size() == 3) {
                if ( vec[0] == trip[0] && \
                     vec[1] == trip[1] && \
                     vec[2] == trip[2] ) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        vector<vector<int>> result {};

        //int last = 0xffffffff >> 1;
        for (int x = 0; x < static_cast<int>(nums.size()) - 2; x++) {
            int y = x + 1;
            int z = nums.size() - 1;

            while ( y < z ) {
                int ret = nums[x] + nums[y] + nums[z] - target;
                /* 
                if ( absoluteCompare(ret, last) < 0 ) {
                    last = ret;
                    result = last + target;
                }
                */
                if ( ret > 0) {
                    z--;
                } else if ( ret < 0) {
                    y++; 
                } else if ( ret == 0 ) {
                    // return target;
                    vector<int> trip { nums[x], nums[y], nums[z] };
                    if (!hasTriplet(result, trip )) {
                        result.emplace_back(trip);
                    }
                    z--;
                    y++;
                }
            }
        }

        return result;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result_set {};

        if ( nums.size() < 4 ) {
            return result_set;
        }

        for ( auto it = nums.begin(); it != nums.end() - 3; it++ ) {
            int subtarget = target - *it;

            if (( subtarget >= 0 && *(it + 1) > subtarget) || 
                ( subtarget < 0 && *(it + 1) > 0 )) {
                break;
            } else {
                //vector<vector<int>> sub_result = {};
                if (it != nums.begin() && *(it - 1) == *it) {
                    continue;
                }

                vector<int> sub_vec {it + 1, nums.end()};
                auto sub_result = threeSum(sub_vec, subtarget);
                if (sub_result.size() != 0) {
                    for ( auto &vs : sub_result ) {
                        result_set.emplace_back(vector<int>{*it, vs[0], vs[1], vs[2]});
                    }
                }
            }
            /* } else {
                break;
            } */
        }

        //result_set.push_back(nums);
        return result_set;
    }
};

#ifdef TEST
void sortSetItems(vector<vector<int>> &set) {
    for (auto &it : set) {
        std::sort(it.begin(), it.end());
    }
}

bool quadrupletEqual(vector<int> &vec1, vector<int> &vec2) {
    if ((vec1.size() != 4) || (vec2.size() != 4)) 
        return false;

    for (int i = 0; i < 4; i++) {
        if (vec1[i] != vec2[i]) 
            return false;
    }

    return true;
}

bool operator==(vector<vector<int>> &set1, vector<vector<int>> &set2) {
    if (set1.size() != set2.size()) 
        return false;

    sortSetItems(set1);
    sortSetItems(set2);

    for ( auto &it1 : set1 ) {
        bool itInSet2 = false;
        for ( auto &it2 : set2 ) {
            if ( quadrupletEqual(it2, it1) ) {
                itInSet2 = true;
                break;
            }
        }

        if ( !itInSet2 ) {
            return false;
        }
    }

    return true;
}

TEST (DISABLED_QuadrupletSetEqual, Equal) {
    vector<vector<int>> set1_a { {1, 2, 3, 4}, {-2, -1, 0, 1} };
    vector<vector<int>> set2_a { {1, 2, 3, 4}, {-2, -1, 0, 1} };
    EXPECT_EQ(true, set1_a == set2_a);


    vector<vector<int>> set1_b { {4, 2, 3, 1}, {-2, 1, -1, 0} };
    vector<vector<int>> set2_b { {-2, -1, 0, 1}, {1, 2, 3, 4} };
    EXPECT_EQ(true, set1_b == set2_b);

    vector<vector<int>> set1_c { {0, 0, 0, 0} };
    vector<vector<int>> set2_c { {0, 0, 0, 0} };
    EXPECT_EQ(true, set1_c == set2_c);
}

TEST (DISABLED_QuadrupletSetEqual, NotEqual) {
    vector<vector<int>> set1_a { {4, 2, 3, 1}, {-2, 1, -1, 0} };
    vector<vector<int>> set2_a { {-2, -1, 0, 1} };
    EXPECT_EQ(false, set1_a == set2_a);

    vector<vector<int>> set1_b { {4, 2, 3, 1}, {-2, 1, -1, 0} };
    vector<vector<int>> set2_b { {-2, -1, 0, 1}, {2, 4, 1, 1} };
    EXPECT_EQ(false, set1_b == set2_b);
}

TEST (QuadrupletSum, DISABLED_RandIntArray) 
{
    Solution sl;
    vector<int> nums1 { -33, 6, -8, 90, 22, 1, 59, 69, 27, -20 };
    vector<vector<int>> expect_ret { { -20, -20, 6, 90 }, { -20, -20, 27, 69 }, { -20, 1, 6, 69 }, { 1, 6, 22, 27 } };
    EXPECT_EQ(expect_ret, sl.fourSum(nums1, 56));
}

TEST (QuadrupletSum, DISABLED_SepecialArray) {
    Solution sl;
    vector<int> nums1 { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    vector<vector<int>> expect_ret { {0, 0, 0, 0} };
    EXPECT_EQ(expect_ret, sl.fourSum(nums1, 0));

    vector<int> nums2 {1,0,-1,0,-2,2};
    vector<vector<int>> expect_ret2 { {-2,-1,1,2}, {-2,0,0,2}, {-1,0,0,1} };
    EXPECT_EQ(expect_ret2, sl.fourSum(nums2, 0));

    vector<int> nums3 {-3,-2,-1,0,0,1,2,3};
    vector<vector<int>> expect_ret3 {{-3,-2,2,3},{-3,-1,1,3},{-3,0,0,3},{-3,0,1,2},{-2,-1,0,3},{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}};
    EXPECT_EQ(expect_ret3, sl.fourSum(nums3, 0));

    vector<int> nums4 {1,-2,-5,-4,-3,3,3,5};
    vector<vector<int>> expect_ret4 {{-5,-4,-3,1}};
    EXPECT_EQ(expect_ret4, sl.fourSum(nums4, -11));
}

TEST (QuadrupletSum, LeetCodeFailed) {
    Solution sl;

    vector<int> nums1 {-1,-3,-2,2,3,-3,0,-4};
    vector<vector<int>> expect_ret1 {{-1,0,2,3}};
    EXPECT_EQ(expect_ret1, sl.fourSum(nums1, 4));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
