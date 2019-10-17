#include <unordered_map>

class Solution {
public:
    int countPossibilities(unordered_map<char, int>& charMap, int len) {
        if (len == 0) return 0;
        int sum = 0;
        for (auto& item : charMap) {
            if (item.second > 0) {
                item.second--;
                sum += 1 + countPossibilities(charMap, len - 1);
                item.second++;
            }
        }
        return sum;
    }
    
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> charMap;
        for (char t : tiles) {
            charMap[t]++;
        }
        return countPossibilities(charMap, tiles.size());
    }
};