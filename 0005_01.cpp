#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int len_str = s.size();
        int len_max = 0;
        string result;
        for (int i = 0; i < len_str; i++) {
            // odd
            int begin = i;
            int end = i;
            while (begin >= 0 && end < len_str && s[begin] == s[end]) {
                if (end - begin + 1 > len_max) {
                    len_max = end - begin + 1;
                    result = s.substr(begin, len_max);
                }
                begin -= 1;
                end += 1;
            }
            // even
            begin = i;
            end = i + 1;
            while (begin >= 0 && end < len_str && s[begin] == s[end]) {
                if (end - begin + 1 > len_max) {
                    len_max = end - begin + 1;
                    result = s.substr(begin, len_max);
                }
                begin -= 1;
                end += 1;
            }
        }
        return result;
    }
};