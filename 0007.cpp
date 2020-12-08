#include<iostream>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        int rest, rev = 0;
        while (x != 0) {
            rest = x % 10;
            x = x / 10;
            if ((rev <= (INT32_MAX / 10)) && (rev >= (INT32_MIN / 10))) {
                rev = rev * 10 + rest;
            }
            else {
                return 0;
            }
        }
        return rev;
    }
};

int main() {
    Solution solution = Solution();
    int result = solution.reverse(123);
    cout << result << endl;
}