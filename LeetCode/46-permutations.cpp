class Solution {
public:
    void swap(int i, int j, vector<int>& nums) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void helper(int i, vector<int>& perm, vector<vector<int>>& result) {
        if (i == perm.size() - 1) {
            vector<int> v(perm);
            result.push_back(v);
            return;
        }
        for (int j = i; j < perm.size(); j++) {
            swap(i, j, perm);
            helper(i + 1, perm, result);
            swap(i, j, perm);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector<vector<int>> result;
        helper(0, nums, result);
        return result;
    }
};