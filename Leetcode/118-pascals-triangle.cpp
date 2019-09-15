class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                result.push_back({1});
            } else {
                vector<int> row;
                for (int j = 0; j <= i; j++) {
                    if (j == 0) {
                        row.push_back(1);
                    } else if (j == i) {
                        row.push_back(1);
                    } else {
                        int elem = result[i-1][j-1] + result[i-1][j];
                        row.push_back(elem);
                    }
                }
                result.push_back(row);
            }
        }
        return result;
    }
};