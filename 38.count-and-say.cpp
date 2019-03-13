/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.64%)
 * Total Accepted:    262.5K
 * Total Submissions: 662K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */

/* #include <iostream>
using namespace std; */

class Solution {
public:
    string countAndSay(int n) {

        string str {""};
        string result{"1"};
        for (--n; n > 0; n--)
        {
            str = result;
            result = "";
            int count = 0;
            char cnum = 0;
            for (auto &ch : str)
            {
                if (count == 0)
                {
                    cnum = ch;
                    count++;
                    continue;
                }

                if (cnum == ch)
                {
                    count++;
                }
                else
                {
                    result.push_back(char(count + 48));
                    result.push_back(cnum);
                    count = 1;
                    cnum = ch;
                }
            }
            result.push_back(char(count + 48));
            result.push_back(cnum);
            /* cout << result  << endl;  */
        }
        return result;
    }
};

/* int main()
{
    Solution sl;
    
    cout << sl.countAndSay(4) << endl;
    return 0;
} */
