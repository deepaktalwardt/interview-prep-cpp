class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return len;
        }
        int slow = 0;
        int fast = 1;
        
        while (fast < len) {
            if (nums[slow] == nums[fast]) {
                fast++;
            } else {
                nums[++slow] = nums[fast++];
            }
        }
        if (slow < len - 1) {
            nums.erase(nums.begin() + slow + 1, nums.end());
        }
        return slow + 1;
    }
};