/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#ifdef TEST
#include <vector>
#include <iostream>

using namespace std;
#endif // TEST 
/*
思路：假设两端的杆子构成的水桶切割面积最大，从两端向中间查找的过程中，由于长度变短，
只有高度超过原来杆子的高度，才有可能获得更大的面积。因此每次从较短的那根杆子向中间
查找，找到高度更高的杆子，记一次当前面积，和上次最大面积比较决定是否要更新最大面积。
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int b = 0, e = height.size() - 1;
        int max_area = min(height[b], height[e]) * (e - b) ;
        cout << max_area << endl;
        int cur_area = 0;
        int i = 0, j = height.size() - 1;
        for (; j > i; )  {
            if (height[i] < height[j]) {
                i++;
#ifdef TEST
                cout << "i";
                for (auto index = 0; index < i; index++)
                {
                    cout << "+";
                }
                cout << endl;
#endif // TEST

                if (height[i] > height[b])
                {
                    b = i;
                    cur_area = min(height[i], height[e]) * (e - i);
                    if (cur_area > max_area)
                    {
                        max_area = cur_area;
                    }
                }
            } else {
                j--;
#ifdef TEST
                cout << "j";
                for (auto index = 0; index < j; index++)
                {
                    cout << "-";
                }
                cout << endl;
#endif // TEST
                if (height[j] > height[e])
                {
                    e = j;
                    cur_area = min(height[b], height[j]) * (j - b);
                    if (cur_area > max_area)
                    {
                        max_area = cur_area;
                    }
                }
            }
        }

#ifdef TEST
        cout << "i: " << i << ", j: " << j << endl;
        cout << "b: " << b << ", e: " << e << endl;
        cout << "height[b]: " << height[b] << ", height[e]: " << height[e] << endl;
#endif // TEST
        return max_area;
    }
};
// @lc code=end

#ifdef TEST
int main()
{
    Solution sl;
    cout << min(3, 4) << endl;
    vector<int> height = {2,3,4,5,18,17,6};
    cout << sl.maxArea(height) << endl;
    return 0;
}
#endif // DEBUG