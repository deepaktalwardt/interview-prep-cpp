
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if (matrix.size() == 0) return {};
        
        int r_beg = 0;
        int r_end = matrix.size() - 1;
        int c_beg = 0;
        int c_end = matrix[0].size() - 1;
        vector<int> result;
        
        while (r_beg <= r_end && c_beg <= c_end) {
            for (int i = c_beg; i <= c_end; i++) {
                result.push_back(matrix[r_beg][i]);
            }
            r_beg++;
            
            for (int i = r_beg; i <= r_end; i++) {
                result.push_back(matrix[i][c_end]);
            }
            c_end--;
            
            if (r_beg <= r_end) {
                for (int i = c_end; i >= c_beg; i--) {
                    result.push_back(matrix[r_end][i]);
                }
            }
            r_end--;
            
            if (c_beg <= c_end) {
                for (int i = r_end; i >= r_beg; i--) {
                    result.push_back(matrix[i][c_beg]);
                }
            }
            c_beg++;
        }
        return result;
    }
};