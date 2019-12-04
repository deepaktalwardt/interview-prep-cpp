class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int n = strs.size();
        if (n == 0) return result;
        int c = 0;
        while (c < strs[0].size()) {
            for (int i = 1; i < n; i++) {
                if (c >= strs[i].size() || strs[i][c] != strs[0][c]) {
                    return strs[0].substr(0, c);
                }
            }
            c++;
        }
        return strs[0].substr(0, c);
    }
};
