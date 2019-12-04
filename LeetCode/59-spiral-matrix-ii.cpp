class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int r_beg = 0;
        int r_end = n - 1;
        int c_beg = 0;
        int c_end = n - 1;
        int val = 1;
        while (r_beg <= r_end && c_beg <= c_end) {
            for (int i = c_beg; i <= c_end; i++) {
                result[r_beg][i] = val++;
            }
            r_beg++;
            for (int i = r_beg; i <= r_end; i++) {
                result[i][c_end] = val++;
            }
            c_end--;
            for (int i = c_end; i >= c_beg; i--) {
                result[r_end][i] = val++;
            }
            r_end--;
            for (int i = r_end; i >= r_beg; i--) {
                result[i][c_beg] = val++;
            }
            c_beg++;
        }
        return result;
    }
};