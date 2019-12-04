class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return {};
        } 
        vector<vector<string>> result;
        unordered_map<string, int> m;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            auto it = m.find(s);
            if (it != m.end()) {
                result[it->second].push_back(strs[i]);
            } else {
                m[s] = idx;
                result.push_back({strs[i]});
                idx++;
            }
        }
        return result;
    }
};