#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int len_str = s.length();
        int len_max = 0;
        int begin = 0;
        int* dp = new int[len_str * len_str];
        for (int j = 0; j < len_str; j++) {
            for (int i = 0; i <= j; i++) {
                dp[i * len_str + j] = 0;
                if (i == j) {
                    dp[i * len_str + j] = 1;
                }
                else if(j - i == 1 or j - i == 2) {
                    if (s[i] == s[j]) {
                        dp[i * len_str + j] = 1;
                    }
                }
                else {
                    if (s[i] == s[j] && dp[(i + 1) * len_str + j - 1]) {
                        dp[i * len_str + j] = 1;
                    }
                }
                if (dp[i * len_str + j] == 1) {
                    if (j - i + 1 > len_max) {
                        len_max = j - i + 1;
                        begin = i;
                    }
                }
            }
        }
        delete[] dp;
        return s.substr(begin, len_max);
    }
};

//int main() {
//    Solution solution = Solution();
//    string result = solution.longestPalindrome("ccc");
//    cout << result << endl;
//    return 0;
//}