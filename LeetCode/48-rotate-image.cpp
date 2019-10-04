class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r_beg = 0;
        int r_end = matrix.size() - 1;
        int c_beg = 0;
        int c_end = matrix[0].size() - 1;
        
        while (r_beg <= r_end && c_beg <= c_end) {
            
            for (int i = 0; i < c_end - c_beg; i++) {
                int tmp1 = matrix[r_beg][c_beg + i]; 
                int tmp2 = matrix[r_beg + i][c_end];  
                
                matrix[r_beg][c_beg + i] = matrix[r_end - i][c_beg];
                matrix[r_beg + i][c_end] = tmp1;
                
                tmp1 = matrix[r_end][c_end - i];
                matrix[r_end][c_end - i] = tmp2;
                
                matrix[r_end - i][c_beg] = tmp1;
            }
            
            r_beg++;
            r_end--;
            c_beg++;
            c_end--;
            
        }
    }
};