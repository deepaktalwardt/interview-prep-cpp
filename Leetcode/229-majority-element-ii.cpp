// Map based solution
// Runs in O(n) time but also takes O(n) space
// Not optimal in terms of space
#include <unordered_map>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int times = nums.size() / 3;
        unordered_map<int, int> counts;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (counts.find(nums[i]) == counts.end()) {
                counts[nums[i]] = 1;
            } else {
                counts[nums[i]]++;
            }
        }
        for (auto it = counts.begin(); it != counts.end(); it++) {
            if (it->second > times) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};

// Using Boyer-Moore Majority Vote algorithm
// Runs in O(n) time, O(1) space
// Optimal, this is what the interviewer wants!!!
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int cand1 = -1;
        int cand2 = -1;
        int count1 = 0;
        int count2 = 0;
        for (int elem : nums) {
            if (elem == cand1) {
                count1++;
            } else if (elem == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = elem;
                count1++;
            } else if (count2 == 0) {
                cand2 = elem;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> result;
        if (count(nums.begin(), nums.end(), cand1) > nums.size()/3) result.push_back(cand1);
        if (count(nums.begin(), nums.end(), cand2) > nums.size()/3) result.push_back(cand2);
        return result;
    }
};