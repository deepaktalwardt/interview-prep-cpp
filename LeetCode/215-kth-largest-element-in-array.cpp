// Solution 1: Sorting based O(NlogN) and O(1) memory
#include <algorithm>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

// Solution 2: Max heap method O(Nlogk) and O(k) memory
#include <queue>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                min_heap.emplace(nums[i]);
            } else {
                if (nums[i] > min_heap.top()) {
                    min_heap.pop();
                    min_heap.emplace(nums[i]);
                }
            }
        }
        return min_heap.top();
    }
};