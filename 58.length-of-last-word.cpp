/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.17%)
 * Total Accepted:    250.2K
 * Total Submissions: 777.8K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
/* #include <iostream>
using namespace std;
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
        
        bool bCount = false;
        auto r_it = s.crbegin();
        auto begin_it = r_it;
        for ( ; r_it != s.crend(); r_it++) {
            if (!bCount && *r_it != ' ') {
                bCount = true;
                begin_it = r_it;
            }
            if (bCount && *r_it == ' ')
                return  r_it - begin_it;
        }
        if (!bCount)
            return 0;
        return s.crend() - begin_it;
    }
};
/* 
int main()
{
    Solution sl;
    string s {"Hello World"};

    cout << "\"" << s << "\" : " << sl.lengthOfLastWord(s) << endl;

    s = "World";
    cout << "\"" << s << "\" : " << sl.lengthOfLastWord(s) << endl;

    s = "";
    cout << "\"" << s << "\" : " << sl.lengthOfLastWord(s) << endl;

    s = "a ";
    cout << "\"" << s << "\" : " << sl.lengthOfLastWord(s) << endl;

     return 0;
}
 */
