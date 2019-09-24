class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int rows = M.size();
        int cols = M[0].size();
        vector<vector<int>> neighbors = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int sum = 0;
                int num = 0;
                for (vector<int>& n : neighbors) {
                    int x = i + n[0];
                    int y = j + n[1];
                    if (x >= 0 && y >= 0 && x < rows && y < cols) {
                        sum += M[x][y];
                        num++;
                    }
                }
                result[i][j] = sum/num;
            }
        }
        return result;
    }
};