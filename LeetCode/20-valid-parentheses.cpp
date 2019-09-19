#include <stack>
class Solution {
public:
    bool isOpening(const char& c) {
        if (c == '(' || c == '[' || c == '{') return true;
        return false;
    }
    
    bool isComplement(const char& a, const char& b) {
        if (a == '(' && b == ')') return true;
        if (a == '{' && b == '}') return true;
        if (a == '[' && b == ']') return true;
        return false;
    }
    
    
    bool isValid(string s) {
        if (s.length() == 0) {
            return true;
        }
        stack<char> bracketStack;
        for (auto it = s.cbegin(); it != s.cend(); it++) {
            if (isOpening(*it)) {
                bracketStack.push(*it);
            } else {
                if (!bracketStack.empty() && isComplement(bracketStack.top(), *it)) {
                    bracketStack.pop();
                } else {
                    return false;
                }
            }
        }
        if (bracketStack.empty()) return true;
        return false;
    }
};