class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_set<char> uniqueChars;
        int longest = 0;
        int N = s.size();
        if (N <= 1) return N;
        for (int j = 0; j < N; j++) {
            int currSize = 0;
            for (int i = j; i < N; i++) {
                char c = s[i];
                uniqueChars.insert(c);
                if (uniqueChars.size() <= 2) {
                    currSize++;
                } else {
                    uniqueChars.clear();
                    break;
                }
            }
            longest = longest < currSize ? currSize : longest;
        }
        return longest;
    }
};