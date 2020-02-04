/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start

#ifdef __MAIN__
#include<iostream>
#include<string>
#include<bitset>
#include<sstream>
#include<algorithm>

using namespace std;
#endif

class Solution {
public:
    char mergebit(string & result, char a, char b , char c) {
        char base = '0';
        int tmp = a + b + c - base*3;
        if (tmp == 0) {
            // 0 + 0 + 0
            result.push_back('0');
            return '0';
        } else if (tmp == 1) {
            // 1 + 0 + 0
            result.push_back('1');
            return '0';
        } else if (tmp == 2) {
            // 1 + 1 + 0
            result.push_back('0');
            return '1';
        } else if (tmp == 3) {
            // 1 + 1 + 1
            result.push_back('1');
            return '1';
        } else {
            // never execute
        }
        return -1;
    }

    string addBinary(string a, string b) {
        string result("");
        string * p1 = nullptr;
        string * p2 = nullptr;

        #ifdef __MAIN__
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        #endif // __MAIN__

        if (b.length() > a.length()) {
            p1 = &b;
            p2 = &a;
        } else {
            p1 = &a;
            p2 = &b;
        }

        auto it1 = p1->crbegin();
        auto it2 = p2->crbegin();
        char last = '0';
        while (it1 != p1->crend() && it2 != p2->crend()) {
            last = mergebit(result, *it1, *it2, last);
            it1++;
            it2++;
        }

        while (it1 != p1->crend()) {
            last = mergebit(result, *it1, '0', last);
            it1++;
        }

        if (last == '1')
            result.push_back('1');

        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

#ifdef __MAIN__
int main()
{
    Solution sl;

    string as, bs;
#if 0
    int a = 5;
    int b = 7;
    std::bitset<sizeof(char) * 8> abit(a);
    std::ostringstream  ss;
    ss << abit;
    std::cout << ss.str() << std::endl;
    as = ss.str();

    ss.str("");
    std::bitset<sizeof(char) * 8> bbit(b);
    ss << bbit;
    std::cout << ss.str() << std::endl;
    bs = ss.str();
#endif

    // case 1
    std::cout << "case 1" << std::endl;
    as = "0";
    bs = "0";
    std::cout << sl.addBinary(as, bs) << std::endl; ;
    std::cout << std::endl;

    // case 2
    std::cout << "case 2" << std::endl;
    as = "1";
    bs = "0";
    std::cout << sl.addBinary(as, bs) << std::endl; ;
    std::cout << std::endl;

    // case 3
    std::cout << "case 3" << std::endl;
    as = "1";
    bs = "1";
    std::cout << sl.addBinary(as, bs) << std::endl; ;
    std::cout << std::endl;

    // case 4
    std::cout << "case 4" << std::endl;
    as = "11";
    bs = "1";
    std::cout << sl.addBinary(as, bs) << std::endl; ;
    std::cout << std::endl;

    // case 5
    std::cout << "case 5" << std::endl;
    as = "1";
    bs = "11";
    std::cout << sl.addBinary(as, bs) << std::endl; ;
    std::cout << std::endl;
    return 0;
}
#endif