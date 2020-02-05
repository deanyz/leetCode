/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#ifdef __MAIN__
#include <iostream>
using namespace std;

#endif //__MAIN__

// @lc code=start
#define PRECISION   0.01
class Solution {
public:
    int mySqrt(int x) {
        double f = x/2.0;
        while ((f*f - x) > PRECISION || (x - f*f) > PRECISION) {
            #ifdef DEBUG 
            std::cout << f << std::endl;
            #endif // DEBUG
            // 牛顿迭代法
            f = f/2 + x/(2*f);
        }

        return int(f);
    }
};
// @lc code=end

#ifdef __MAIN__
int main()
{
    Solution sl;

    // cout << sl.mySqrt(9) << std::endl;
    // cout << sl.mySqrt(4) << std::endl;
    // cout << sl.mySqrt(12) << std::endl;
    // cout << sl.mySqrt(299) << std::endl;
    cout << sl.mySqrt(2147395599) << endl;
    return 0;
}

#endif // __MAIN__
