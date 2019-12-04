class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        vector<vector<int>> result(cols, vector<int>(rows, 0));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                result[c][r] = A[r][c];
            }
        }
        return result;
    }
};