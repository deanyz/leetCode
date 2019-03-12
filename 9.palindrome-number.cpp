/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (42.14%)
 * Total Accepted:    521.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
//#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) 
            return false;
        
        int ltimes = 1;
        int rtimes = 10;
        int r, l;
        int tmp = x;
        while ( 0 != ( tmp = tmp/10)) {
            ltimes *= 10;
        }
        //std::cout << ltimes << std::endl;

        while (ltimes >= rtimes) {
            r = x % rtimes / (rtimes/10);
            l = x / ltimes % 10;
            if (r != l)
                return false;
            //std::cout << "x[" << x << "]  " << r << "   " << l << std::endl;
            //std::cout << "ltimes [" << ltimes << "]  rtimes [" << rtimes << "]" << std::endl;
            ltimes /= 10;
            rtimes *=10;
        }
        

        return true;
    }
};

/*
int main()
{
    Solution sl;
    bool ret;

    ret = sl.isPalindrome(122321);
    std::cout << ret << std::endl;

    return 0;
}
*/
