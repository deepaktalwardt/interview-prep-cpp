class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.length() == 0 && t.length() == 0) return false;
        if (s.length() == 0 && t.length() == 1 || t.length() == 0 && s.length() == 1) return true;
        int lenDiff = s.length() - t.length();
        if (abs(lenDiff) > 1) return false;
        
        int equal = 0; // default: s and t are of equal length
        if (s.length() > t.length()) {
            equal = -1; // s is longer
        } else if (s.length() < t.length()) {
            equal = 1; // t is longer
        }
        
        auto it1 = s.begin();
        auto it2 = t.begin();
        
        int numDiff = 0;
        
        while (it1 != s.end() && it2 != s.end()) {
            if (*it1 == *it2) {
                it1++;
                it2++;
            } else {
                numDiff++;
                if (equal == 0) {
                    it1++;
                    it2++;
                } else if (equal == -1) {
                    it1++;
                } else if (equal == 1) {
                    it2++;
                }
                if (numDiff > 1) {
                    return false;
                }
                
            }
        }
        if (numDiff == 1 || numDiff == 0 && (it1 != s.end() || it2 != t.end())) {
            return true;
        }
        return false;
    }
};