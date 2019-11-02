class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            result[i] = nums[i - 1] * result[i - 1];
        }
        int prevProduct = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int product = nums[i + 1] * prevProduct;
            result[i] = result[i] * product;
            prevProduct = product;
        }
        return result;
    }
};