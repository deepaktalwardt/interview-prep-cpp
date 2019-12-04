class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> minWays(amount + 1, 1000); // 1000 is arbitrary high number, so that 1 + minWays[amt - denom] doesn't overflow. INT_MAX will overflow.
        minWays[0] = 0;
        for (int& denom : coins) {
            for (int amt = 0; amt < minWays.size(); amt++) {
                if (denom <= amt) {
                    minWays[amt]= min(minWays[amt], 1 + minWays[amt - denom]);
                }
            }
        }
        return minWays[minWays.size() - 1] != 1000 ? minWays[minWays.size() - 1] : -1;
    }
};