class Solution {
public:
    bool findWord(vector<vector<char>>& board, string word, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> deltas = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        deque<pair<int,int>> path;
        stack<vector<int>> s;
        s.push({i, j, 0});
        while (!s.empty()) {
            vector<int> curr = s.top();
            s.pop();
            int x = curr[0];
            int y = curr[1];
            int k = curr[2];
            while (path.size() != k) {
                path.pop_back();
            }
            if (k == word.size() - 1) {
                return true;
            }
            path.push_back(make_pair(curr[0], curr[1]));
            for (auto& d : deltas) {
                int newX = x + d[0];
                int newY = y + d[1];
                pair<int,int> currLoc = make_pair(newX, newY);
                bool notInPath = find(path.begin(), path.end(), currLoc) == path.end();
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && word[k + 1] == board[newX][newY] && notInPath) {
                    s.push({newX, newY, k + 1});
                }
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0) return false;
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    bool found = findWord(board, word, i, j);
                    if (found) return true;
                }
            }
        }
        return false;
    }
};