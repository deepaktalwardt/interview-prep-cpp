class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxPrev = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int curr = max(nums[i], nums[i] + maxPrev);
            result = max(result, curr);
            maxPrev = curr;
        }
        return result;
    }
};
