// Time: O(N), Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }
        int prevPrev = nums[0];
        int prev = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            int curr = max(prev, nums[i] + prevPrev);
            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
};


// Time: O(N), Space: O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }
        vector<int> profit(len, 0);
        profit[0] = nums[0];
        profit[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            profit[i] = max(profit[i - 1], nums[i] + profit[i - 2]);
        }
        return profit[len - 1];
    }
};