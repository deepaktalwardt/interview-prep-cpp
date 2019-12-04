// Dynamic Programming: Time O(mn), Space: O(mn)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        vector<vector<int>> maxSquareCorner(rows + 1, vector<int>(cols + 1, 0));
        int result = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    maxSquareCorner[i][j] = min(maxSquareCorner[i - 1][j - 1], min(maxSquareCorner[i - 1][j], maxSquareCorner[i][j - 1])) + 1;
                    result = max(result, maxSquareCorner[i][j]);
                }
            }
        }
        return result * result;
    }
};

// Brute force Time: O((mn)^2), Space: O(1)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        int maxLevel = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int currArea = 0;
                if (!visited[i][j] && matrix[i][j] == '1') {
                    currArea = 1;
                    int level = 1;
                    bool flag = true;
                    while (i + level < rows && j + level < cols && flag) {
                        for (int k = j; k <= j + level; k++) {
                            if (matrix[i + level][k] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        for (int k = i; k <= i + level; k++) {
                            if (matrix[k][j + level] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            level++;
                        }
                    }
                    maxLevel = max(maxLevel, level);
                }
            }
        }
        return maxLevel * maxLevel;
    }
};