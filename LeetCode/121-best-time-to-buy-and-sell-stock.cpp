class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxDiff = 0;
        int minSoFar = INT_MAX;
        for (int n : prices) {
            minSoFar = min(minSoFar, n);
            maxDiff = max(maxDiff, n - minSoFar);
        }
        return maxDiff;
    }
};