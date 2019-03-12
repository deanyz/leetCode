/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.17%)
 * Total Accepted:    623.6K
 * Total Submissions: 2.5M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */

class Solution
{
  public:
    int reverse(int x)
    {
        if (x == INT_MIN) {
            return 0;
        }

        int tmp = x < 0 ? -x : x;
        long long ret = 0;
        while (0 != (tmp / 10))
        {
            ret = 10 * ret + tmp % 10;
            tmp = tmp / 10;
        }
        ret = 10 * ret + tmp % 10;
        if (ret > INT_MAX)
        {
            return 0;
        }
        ret = x < 0 ? -ret : ret;
        return (int)ret;
    }
};

