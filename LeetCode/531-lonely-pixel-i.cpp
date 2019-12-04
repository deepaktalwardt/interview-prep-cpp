class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int rows = picture.size();
        if (rows == 0) return 0;
        int cols = picture[0].size();
        vector<int> blackRows(rows, 0);
        vector<int> blackCols(cols, 0);
        int result = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (picture[i][j] == 'B') {
                    blackRows[i]++;
                    blackCols[j]++;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (picture[i][j] == 'B' && blackRows[i] == 1 && blackCols[j] == 1) {
                    result++;
                }
            }
        }
        return result;
    }
};