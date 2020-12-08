#include<vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int vec_length = nums.size();
        vector<int> result;
        for (int i = 0; i < vec_length - 1; i++) {
            for (int j = i + 1; j < vec_length; j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};