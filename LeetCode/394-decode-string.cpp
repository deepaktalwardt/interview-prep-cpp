#include <stack>

class Solution {
public:    
    string decodeString(string s) {
        stack<string> decodedStack;
        stack<int> numStack;
        decodedStack.push("");
        int numBegin = -1;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]) && numBegin == -1) {
                numBegin = i;
            } else if (s[i] == '[') {
                numStack.push(stoi(s.substr(numBegin, i - numBegin)));
                numBegin = -1;
                decodedStack.push("");
            } else if (s[i] == ']') {
                string decodedString;
                for (int j = 0; j < numStack.top(); j++) {
                    decodedString += decodedStack.top();
                }
                decodedStack.pop();
                numStack.pop();
                decodedStack.top() += decodedString;
            } else if (numBegin == -1) {
                decodedStack.top() += s[i];
            }
        }
        return decodedStack.top();
    }
};