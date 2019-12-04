// Iterative solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftIdx = 0;
        int rightIdx = nums.size() - 1;
        
        while (leftIdx <= rightIdx) {
            int midIdx = (leftIdx + rightIdx) / 2;
            if (nums[midIdx] == target) {
                return midIdx;
            }
            if (nums[leftIdx] <= nums[midIdx]) { // left is sorted
                if (target >= nums[leftIdx] && target < nums[midIdx]) {
                    rightIdx = midIdx - 1;
                } else {
                    leftIdx = midIdx + 1;
                }
            } else { // right is sorted
                if (target > nums[midIdx] && target <= nums[rightIdx]) {
                    leftIdx = midIdx + 1;
                } else {
                    rightIdx = midIdx - 1;
                }
            }
        }
        return -1;
    }
};

// Recursive solution
class Solution {
public:
    int shiftedBinarySearch(vector<int>&nums, int target, int leftIdx, int rightIdx) {
        if (leftIdx > rightIdx) return -1;
        int mid = (leftIdx + rightIdx) / 2;
        int leftNum = nums[leftIdx];
        int rightNum = nums[rightIdx];
        int midNum = nums[mid];
        if (midNum == target) {
            return mid;
        }
        if (leftNum <= midNum) { // left is sorted
            if (target >= leftNum && target < midNum) {
                return shiftedBinarySearch(nums, target, leftIdx, mid - 1);
            } else {
                return shiftedBinarySearch(nums, target, mid + 1, rightIdx);
            }
        } else { // right is sorted
            if (target > midNum && target <= rightNum) {
                return shiftedBinarySearch(nums, target, mid + 1, rightIdx);
            } else {
                return shiftedBinarySearch(nums, target, leftIdx, mid - 1);
            }
        }
    }
    
    int search(vector<int>& nums, int target) {
        return shiftedBinarySearch(nums, target, 0, nums.size() - 1);
    }
};