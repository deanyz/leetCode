/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#ifdef TEST
#include <iostream>
#endif
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {return 1;}
        else if (n == 2) {return 2;}
        //else
        //{
        //    return (climbStairs(n - 1) + climbStairs(n - 2));
        //}
        int a = 1, b = 2, c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
// @lc code=end

#ifdef TEST
int main()
{
    Solution sl;
    std::cout << "3, 4, 5, 6, 20, 45" << std::endl;
    std::cout << sl.climbStairs(3) << std::endl;
    std::cout << sl.climbStairs(4) << std::endl;
    std::cout << sl.climbStairs(5) << std::endl;
    std::cout << sl.climbStairs(6) << std::endl;
    std::cout << sl.climbStairs(20) << std::endl;
    std::cout << sl.climbStairs(45) << std::endl;
    return 0;
}
#endif
