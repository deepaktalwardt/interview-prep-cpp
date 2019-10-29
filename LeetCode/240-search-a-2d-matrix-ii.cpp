class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;
        int cols = matrix[0].size();
        int currRow = 0;
        int currCol = cols - 1;
        while (currRow < rows && currCol >= 0) {
            if (matrix[currRow][currCol] == target) {
                return true;
            } else if (matrix[currRow][currCol] < target) {
                currRow++;
            } else {
                currCol--;
            }
        }
        return false;
    }
};