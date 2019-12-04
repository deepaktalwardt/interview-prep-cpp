class Solution {
public:
    bool binarySearch(vector<int>& row, int target, int start, int end) {
        if (start >= end) {
            return false;
        }
        int mid = (start + end) / 2;
        if (row[mid] == target) {
            return true;
        } else if (row[mid] < target) {
            return binarySearch(row, target, mid + 1, end);
        } else {
            return binarySearch(row, target, start, mid);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (!rows) return false;
        int cols = matrix[0].size();
        if (!cols) return false;
        for (int r = 0; r < rows; r++) {
            if (target >= matrix[r][0] && target <= matrix[r][cols - 1]) {
                return binarySearch(matrix[r], target, 0, cols);
            }
        }
        return false;
    }
};