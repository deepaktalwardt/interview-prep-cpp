class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.length() != B.length()) return false;
        
        string bothStrings = A + A;
        
        return bothStrings.find(B) != string::npos;
    }
};