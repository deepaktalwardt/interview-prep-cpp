class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int prevPrev = 1; // Number of ways to climb staircase of len 1
        int prev = 2; // Number of ways to climb staircase of len 2
        for (int i = 3; i < n + 1; i++) {
            int curr = prevPrev + prev; 
            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
};