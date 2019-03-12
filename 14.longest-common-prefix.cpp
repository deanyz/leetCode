/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.06%)
 * Total Accepted:    418.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
/*
#include <iostream>
#include <vector>
using namespace std;
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret{""};

        if (strs.size() == 0) {
            return ret;
        } else if (strs.size() == 1) {
            return strs[0];
        }

        string &fstStr = strs[0];
        for (int index = 0; index < fstStr.length(); index++) {
            auto it = strs.begin();
            bool bBreak = false;
            for (it++; it != strs.end(); it++) {
                if (index >= (*it).length())  { bBreak = true;  break;}
                //std::cout << "first : " << fstStr[index] << " second : " << (*it)[index] << std::endl;
                if ( fstStr[index] != (*it)[index] ) {bBreak = true; break;}
            }

            if (!bBreak)  
                ret.push_back(fstStr[index]);
            else 
                break;
        }
        return ret;
    }
};

/*
int main() {
    Solution sl;

    vector<string> vec { "aca","cba"};
    string ret = sl.longestCommonPrefix(vec);
    std::cout <<"longest prefix :" << ret << std::endl;
    return 0;
}
*/
