// Recursive DFS (Fast)
class Solution {
public:
    bool findWord(vector<vector<char>>& board, string& word, int i, int j, int pos, int& rows, int& cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            return false;
        }
        
        if (pos == word.size() - 1) return true;
        
        char tempChar = board[i][j];
        board[i][j] = '$';
        
        bool found = false;
        if (i + 1 < rows && board[i + 1][j] == word[pos + 1]) {
            found = found || findWord(board, word, i + 1, j, pos + 1, rows, cols);
        }
        if (i - 1 >= 0 && board[i - 1][j] == word[pos + 1]) {
            found = found || findWord(board, word, i - 1, j, pos + 1, rows, cols);
        }
        if (j + 1 < cols && board[i][j + 1] == word[pos + 1]) {
            found = found || findWord(board, word, i, j + 1, pos + 1, rows, cols);
        }
        if (j - 1 >= 0 && board[i][j - 1] == word[pos + 1]) {
            found = found || findWord(board, word, i, j - 1, pos + 1, rows, cols);
        }
        
        board[i][j] = tempChar;
        
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0) return false;
        int cols = board[0].size();
        int pos = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[pos]) {
                    if (word.size() == 1) return true;
                    bool found = findWord(board, word, i, j, pos, rows, cols);
                    if (found) return true;
                }
            }
        }
        return false;
    }
};

// Iterative DFS (Slow)
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