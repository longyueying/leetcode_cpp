#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int len_str = s.length();
        int result = 0;
        int i;
        for (i = 0; i < len_str; i++) {
            if (s[i] != ' ') {
                break;
            }
        }
        if (i == len_str) {
            return 0;
        }
        int positive = 1;
        if (s[i] == '-' or s[i] == '+') {
            if (s[i] == '-') positive = 0;
            i++;
        }

        while (i < len_str && s[i] >= '0' && s[i] <= '9') {
            if (positive) {
                if (result > INT32_MAX / 10 || (s[i] - '0' > INT32_MAX % 10 && result == INT32_MAX / 10)) {
                    return INT32_MAX;
                }
                else {
                    result = result * 10 + (s[i] - '0');
                }
            }
            else {
                if (result > INT32_MAX / 10 || (s[i] - '0' > INT32_MAX  % 10 + 1 && result == INT32_MAX / 10)) {
                    return INT32_MIN;
                }
                else {
                    if ((s[i] - '0' == INT32_MAX % 10 + 1 && result == INT32_MAX / 10)) {
                        return INT32_MIN;
                    }
                    result = result * 10 + (s[i] - '0');
                }
            }
            i++;
        }
        if (positive == 0) {
            return result * -1;
        }
        return result;
    }
};