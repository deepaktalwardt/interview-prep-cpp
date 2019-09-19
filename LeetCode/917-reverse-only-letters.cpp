#import <stack>
#import <vector>
#include <ctype.h>

class Solution {
public:
    string reverseOnlyLetters(string S) {
        stack<char> rev_chars;
        string to_return;
        for (int i = 0; i < S.length(); i++) {
            if (isalpha(S[i])) {
                rev_chars.push(S[i]);
            }
        }
        
        for (int k = 0; k < S.length(); k++) {
            if (isalpha(S[k])) {
                to_return.push_back(rev_chars.top());
                rev_chars.pop();
            } else {
                to_return.push_back(S[k]);
            }
        }
        return to_return;
    }
};