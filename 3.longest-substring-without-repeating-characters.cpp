/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.19%)
 * Total Accepted:    877K
 * Total Submissions: 3.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 */
 /* #include <iostream>
 using namespace std; */

class Solution {
public:
    int chInStr(const string &str, const char &ch) {
        for (size_t i = 0; i < str.length(); i++) {
            if (ch == str[i]) {
                return i;
            }
        }
        return -1;
    }

    /* int lengthOfLongestSubstring(string s) {
        string curStr {""};
        string optStr {""};
        //string prevStr {""};
        bool bOptIsCur = true;
        int ret = 0;
        for (auto & ch : s) {
            ret = chInStr(curStr, ch);
            if (ret == -1) {
                curStr.push_back(ch);
                if (bOptIsCur) 
                    optStr.push_back(ch);
                else if (optStr.length() < curStr.length()) 
                    optStr = curStr; 
            } else {
                //prevStr = curStr;
                curStr = curStr.substr(ret+1);
                curStr.push_back(ch);
                bOptIsCur = false;
            }
        }
        //cout << "optStr: " << optStr << endl;
        return optStr.length();
    } */

    int lengthOfLongestSubstring(string s) {
        string curStr {""};
        // string optStr {""};
        //string prevStr {""};
        size_t curLength = 0;
        size_t optLength = 0;
        bool bOptIsCur = true;
        int ret = 0;
        for (auto & ch : s) {
            ret = chInStr(curStr, ch);
            if (ret == -1) {
                curStr.push_back(ch);
                curLength += 1;
                if (bOptIsCur) 
                    // optStr.push_back(ch);
                    optLength += 1;
                else if ( optLength < curLength ) 
                    optLength = curLength;
            } else {
                //prevStr = curStr;
                //curLength = curLength - ret;
                curStr = curStr.substr(ret + 1);
                curStr.push_back(ch);
                curLength = curStr.length();
                bOptIsCur = false;
            }
        }
        //cout << "optStr: " << optStr << endl;
        return optLength;
    }
};

/* int main(int argc, char **argv)
{
    std::string s{"pwwkew"};
    Solution sl;
    std::cout << sl.lengthOfLongestSubstring(s);
    return 0;
} */
