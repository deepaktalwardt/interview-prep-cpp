// Time: O(N^2), Space: O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        sums[0] = 0;
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        int count = 0;
        for (int start = 0; start < n; start++) {
            for (int end = start + 1; end <= n; end++) {
                if (sums[end] - sums[start] == k) count++;
            }
        }
        return count;
    }
};