class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        if (n == 1 && s[0] == '0') {
            return 0;
        } else if (n == 1) {
            return 1;
        }
        
        vector<int> ways(n + 1, 0);
        ways[n] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                ways[i] = 0;
            } else if (s[i] == '1') {
                ways[i] = ways[i + 1];
                if (i != n - 1) {
                    ways[i] += ways[i + 2];
                }
            } else if (s[i] == '2') {
                ways[i] = ways[i + 1];
                if (i != n - 1 && s[i + 1] < '7') {
                    ways[i] += ways[i + 2];
                }
            } else {
                ways[i] = ways[i + 1];
            }
        }
        return ways[0];
    }
};