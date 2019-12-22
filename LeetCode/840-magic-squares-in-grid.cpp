class Solution {
public:
    bool isMagic(vector<int> vals) {
        vector<int> counts(16, 0);
        for (int v : vals) {
            counts[v]++;
        }
        for (int i = 1; i <= 9; i++) {
            if (counts[i] != 1) return false;
        }
        return vals[0] + vals[1] + vals[2] == 15 &&
               vals[3] + vals[4] + vals[5] == 15 &&
               vals[6] + vals[7] + vals[8] == 15 &&
               vals[0] + vals[4] + vals[8] == 15 &&
               vals[2] + vals[4] + vals[6] == 15 &&
               vals[0] + vals[3] + vals[6] == 15 &&
               vals[1] + vals[4] + vals[7] == 15 &&
               vals[2] + vals[5] + vals[8] == 15;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;
        for (int r = 0; r < rows - 2; r++) {
            for (int c = 0; c < cols - 2; c++) {
                if (isMagic({grid[r][c],   grid[r][c+1],   grid[r][c+2],
                            grid[r+1][c], grid[r+1][c+1], grid[r+1][c+2],
                            grid[r+2][c], grid[r+2][c+1], grid[r+2][c+2]})) {
                    result++;
                }
            }
        }
        return result;
    }
};