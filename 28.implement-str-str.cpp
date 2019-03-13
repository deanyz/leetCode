/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.32%)
 * Total Accepted:    389.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */

/* #include <iostream>
using namespace std; */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length())
            return -1;
        if (needle == "")
            return 0;
        for (auto it_h = haystack.cbegin(); it_h != haystack.cend(); it_h++)
        {
            auto tmp = it_h;
            bool isBreak = false;
            for (auto it_n = needle.cbegin(); it_n != needle.cend(); it_n++, tmp++)
            {
                if (*tmp != *it_n) {
                    isBreak = true;
                    break;
                }
            }
            if (!isBreak) {
                return it_h - haystack.cbegin();
            }
        }

        return -1;
    }
};
/* 
int main()
{
    Solution sl;
    string str1 {"aaaaa"}, str2 {"bba"};

    std::cout << sl.strStr(str1, str2) << std::endl;
    
    str1 = {"hello"};
    str2 = {"ll"};
    std::cout << sl.strStr(str1, str2) << std::endl;
    return 0;
}
 */
