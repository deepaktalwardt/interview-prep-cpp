#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int curr, left, right;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int curr = 0; curr < nums.size(); curr++) {
            if (curr > 0 && nums[curr] == nums[curr - 1]) continue;
            if (nums[curr] > 0) continue;
            left = curr + 1;
            right = nums.size() - 1;
            while (left < right) {
                int sum = nums[curr] + nums[left] + nums[right];
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    result.push_back({nums[curr], nums[left], nums[right]});
                    while (left + 1 < right && nums[left] == nums[left + 1]) left++;
                    while (right - 1 > left && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};