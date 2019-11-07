class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        
        int left = 0;
        int right = n - 1;
        int mid, midNum, leftNum, rightNum;
        
        while (left <= right) {
            mid = (left + right) / 2;
            midNum = nums[mid];
            leftNum = nums[left];
            rightNum = nums[right];
            
            if (midNum == target) {
                return true;
            } else if (leftNum < midNum) { // left array is sorted
                if (target >= leftNum && target <= midNum) {
                    right = mid - 1;
                } else { 
                    left = mid + 1;
                }
            } else if (leftNum > midNum) { // right array is sorted
                if (target >= midNum && target <= rightNum) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                left++;
            }
        }
        return false;
    }
};