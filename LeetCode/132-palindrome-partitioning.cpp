class Solution {
public:
    bool isPalindrome(string str) {
        int n = str.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        if (n <= 1) return 0;
        
        vector<int> minCuts(n, INT_MAX);
        minCuts[0] = 0;
        
        for (int i = 0; i < n; i++) {
            if (isPalindrome(s.substr(0, i + 1))) {
                minCuts[i] = 0;
            } else {
                minCuts[i] = minCuts[i - 1] + 1;
                for (int j = 1; j < i; j++) {
                    if (isPalindrome(s.substr(j, i - j + 1)) && minCuts[i] > minCuts[j - 1] + 1) {
                        minCuts[i] = minCuts[j - 1] + 1;
                    }
                }
            }
        }
        return minCuts[n - 1];
    }
};