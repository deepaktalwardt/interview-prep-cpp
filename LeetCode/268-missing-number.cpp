class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int expectedSum = size * (size + 1) / 2;
        
        int actualSum = 0;
        for (int n : nums) {
            actualSum += n;
        }
        return expectedSum - actualSum;
    }
};