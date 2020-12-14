#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        int len_str = s.length();
        int step1, step2, pos;
        string res;
        if (numRows >= len_str || numRows == 1) {
            return s;
        }
        for (int i = 0; i < numRows; i++) {
            step1 = 2 * (numRows - i) - 2;
            step2 = 2 * numRows - 2 - step1;
            pos = i;
            res += s.at(pos);
            while (1) {
                if (step1) {
                    pos += step1;
                    if (pos >= len_str) {
                        break;
                    }
                    res += s.at(pos);
                }
                if (step2) {
                    pos += step2;
                    if (pos >= len_str) {
                        break;
                    }
                    res += s.at(pos);
                }
            }
        }
        return res;
    }
};