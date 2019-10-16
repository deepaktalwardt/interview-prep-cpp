// Time: O(N), Space: O(N)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int steps = cost.size();
        vector<int> minCost(steps, 0);
        minCost[0] = cost[0];
        minCost[1] = min(cost[0] + cost[1], cost[1]);
        for (int i = 2; i < steps; i++) {
            minCost[i] = cost[i] + min(minCost[i - 1], minCost[i - 2]);
        }
        return min(minCost[steps - 1], minCost[steps - 2]);
    }
};

// Time: O(N), Space: O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int steps = cost.size();
        int prevPrev = cost[0];
        int prev = min(cost[0] + cost[1], cost[1]);
        for (int i = 2; i < steps; i++) {
            int curr = cost[i] + min(prev, prevPrev);
            prevPrev = prev;
            prev = curr;
        }
        return min(prev, prevPrev);
    }
};