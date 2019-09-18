#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            auto it = nums_map.find(comp);
            if (it != nums_map.end()) {
                return {it->second, i};
            }
            nums_map[nums[i]] = i;
        }
        return {};
    }
};