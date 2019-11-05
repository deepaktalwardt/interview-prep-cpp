#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        int maxLen = 0;
        int startIdx = 0;
        unordered_map<char, int> lastSeenAt;
        for (int i = 0; i < s.size(); i++) {
            char currChar = s[i];
            if (lastSeenAt.find(currChar) != lastSeenAt.end()) {
                startIdx = max(startIdx, lastSeenAt[currChar] + 1);
            }
            if (i - startIdx + 1 > maxLen) maxLen = i - startIdx + 1;
            lastSeenAt[currChar] = i;
        }
        return maxLen;
    }
};