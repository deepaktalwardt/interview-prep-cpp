class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0;
        int countConsecL = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'P') {
                countConsecL = 0;
                continue;
            }
            if (s[i] == 'L') {
                countConsecL++;
                if (countConsecL > 2) return false;
            } else if (s[i] == 'A') {
                countA++;
                countConsecL = 0;
                if (countA > 1) return false;
            }
        }
        return true;
    }
};