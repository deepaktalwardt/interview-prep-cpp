class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        if (n == 0) return 0;
        if (n == 1) return costs[0];
        
        vector<int> minCosts(366, 0);
        int currDay = 0;
        int dc = costs[0];
        int wc = costs[1];
        int mc = costs[2];
        
        for (int i = 1; i <= 365; i++) {
            if (currDay == n) {
                break;
            }
            if (days[currDay] != i) {
                minCosts[i] = minCosts[i - 1];
            } else {
                int dailyCost = dc, weeklyCost = wc, monthlyCost = mc;
                if (i > 1) {
                    dailyCost += minCosts[i - 1];
                }
                if (i > 7) {
                    weeklyCost += minCosts[i - 7];
                }
                if (i > 30) {
                    monthlyCost += minCosts[i - 30];
                }
                minCosts[i] = min(dailyCost, min(weeklyCost, monthlyCost));
                currDay++;
            }
        }
        return minCosts[days[n - 1]];
    }
};