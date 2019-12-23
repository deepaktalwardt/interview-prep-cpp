// Faster Solution as we don't clear the hashmap each time
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> uniqueChars;
        int longest = 0;
        int N = s.size();
        if (N <= 2) return N;
        int left = 0;
        int right = 0;
        while (right < N) {
            if (uniqueChars.size() <= 2) {
                uniqueChars[s[right]] = right;
            }
            if (uniqueChars.size() == 3) {
                auto it = min_element(uniqueChars.begin(), uniqueChars.end(), 
                                     [](const auto& l, const auto& r) {
                                         return l.second < r.second;
                                     });
                int leftmost = it->second;
                uniqueChars.erase(s[leftmost]);
                left = leftmost + 1;
            }
            longest = max(longest, right - left + 1);
            right++;
        }
        return longest;
    }
};

// Slower solution becasue set gets cleared each time
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