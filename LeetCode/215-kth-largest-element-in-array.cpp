// Solution 1: Sorting based O(NlogN) and O(1) memory
#include <algorithm>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

// Solution 2: Max heap method O(NlogN) and O(N) memory
#include <queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for (const int& num : nums) {
            max_heap.emplace(num);
        }
        int result;
        while (k) {
            result = max_heap.top();
            max_heap.pop();
            k--;
        }
        return result;
    }
};