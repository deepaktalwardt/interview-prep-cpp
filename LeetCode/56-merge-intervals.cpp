class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {}; 
        if (intervals.size() == 1) return {intervals[0]};
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& v1, const vector<int>& v2) {
               return v1[0] < v2[0]; 
            });
        
        vector<vector<int>> result = {intervals[0]};
        
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> toCompare = result[result.size() - 1];
            if (toCompare[1] >= intervals[i][0]) {
                if (toCompare[1] <= intervals[i][1]) {
                    result[result.size() - 1] = {toCompare[0], intervals[i][1]};
                }
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};