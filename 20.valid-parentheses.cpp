/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.98%)
 * Total Accepted:    528.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */

/*
#include <iostream>
using namespace std;
*/

class Solution {
public:
    bool isValid(string s) {
        bool ret = false;
        string rStr {""};

        if (s.length() == 0)
            return true;
        if (s.back() == '[' || s.back() == '{' || s.back() == '(')
            return false;

        rStr.push_back(s.back());
        s.pop_back();

        while (s.length() > 0) {
            if ((rStr.back() == '}' && s.back() == '{') || 
                (rStr.back() == ')' && s.back() == '(') ||
                (rStr.back() == ']' && s.back() == '[') ) {
                    s.pop_back();
                    rStr.pop_back();
                    
                    if (s.length() == 0 && rStr.length() == 0) {
                        return true;
                    }
            } else {
                rStr.push_back(s.back());
                s.pop_back();
            }
        }
        return ret;
    }
};
/*
int main() 
{
    Solution sl;
    string str {"()"};
    std::cout << sl.isValid(str) << std::endl; 
}
*/
