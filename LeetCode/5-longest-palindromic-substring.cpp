#include <vector>
using namespace std;

class Solution {
public:
    vector<int> longestPalindromeBetween(const string& s, int i, int j) {
        while (i >= 0 && j < s.length()) {
            if (s[i] != s[j]) {
                break;
            }
            i--;
            j++;
        }
        return vector<int> {i+1, j};
    }
    
    string longestPalindrome(string s) {
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            vector<int> odd = longestPalindromeBetween(s, i-1, i+1);
            vector<int> even = longestPalindromeBetween(s, i-1, i);
            vector<int> longest = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
            if (result.length() < longest[1] - longest[0]) {
                result = s.substr(longest[0], longest[1] - longest[0]);
            }
        }
        return result;
    }
};