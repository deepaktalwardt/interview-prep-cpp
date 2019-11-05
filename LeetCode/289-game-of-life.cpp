class Solution {
public:
    void process(vector<vector<int>>& board, int m, int n, int i, int j, vector<vector<int>>& neighbors) {
        int aliveNeighbors = 0;
        for (vector<int>& N : neighbors) {
            int newI = i + N[0];
            int newJ = j + N[1];
            if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && (board[newI][newJ] == 1 || board[newI][newJ] == -2)) {
                aliveNeighbors++;
            }
        }
        if (board[i][j] == 0) {
            if (aliveNeighbors == 3) {
                board[i][j] = -1;
            }
        } else {
            if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                board[i][j] = -2;
            }
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        // 0, 1 remain unchancged
        // 0 -> 1 encode with -1
        // 1 -> 0 encode with -2
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> neighbors = {{-1, 0}, {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, -1}, {1, 1}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                process(board, m, n, i, j, neighbors);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 1;
                } else if (board[i][j] == -2) {
                    board[i][j] = 0;
                }
            }
        }
        
    }
};