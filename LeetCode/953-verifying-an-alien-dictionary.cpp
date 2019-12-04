#include <unordered_map>

class Solution {
public:
    bool inOrder(unordered_map<char, int>& orderMap, vector<string>& words, int i, int j) {
        string word1 = words[i];
        string word2 = words[j];
        int shorterLen = word1.size() < word2.size() ? word1.size() : word2.size();
        for (int k = 0; k < shorterLen; k++) {
            char c1 = word1[k];
            char c2 = word2[k];
            if (c1 == c2) {
                continue;
            } else if (orderMap[c1] < orderMap[c2]) {
                return true;
            } else {
                return false;
            }
        }
        if (shorterLen == word1.size()) {
            return true;
        }
        return false;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> orderMap;
        for (int i = 0; i < order.size(); i++) {
            orderMap[order[i]] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            if (!inOrder(orderMap, words, i - 1, i)) return false;
        }
        return true;
    }
};