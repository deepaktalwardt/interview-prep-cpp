#include <unordered_set>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> canBeSegmented(n + 1, false);
        canBeSegmented[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (canBeSegmented[j]) {
                    string sub = s.substr(j, i - j);
                    if (dict.find(sub) != dict.end()) {
                        canBeSegmented[i] = true;
                        break;
                    }
                }
            }
        }
        return canBeSegmented[n];
    }
};