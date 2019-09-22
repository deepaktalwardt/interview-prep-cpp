// Iterative BFS based solution
// Time: O(mn) Space O(mn)
// However, it runs very slow

#include <queue>
class Solution {
public:
    int exploreIsland(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int result = 0;
        int rows = grid.size();
        int cols = 0;
        if (rows > 0) cols = grid[0].size();
        queue<vector<int>> q;
        q.push({i, j});
        while (!q.empty()) {
            vector<int> front = q.front();
            q.pop();
            i = front[0];
            j = front[1];
            if (visited[i][j]) continue;
            visited[i][j] = true;
            if (grid[i][j] == '1') {
                result = 1;
                if ((i-1 >= 0) && !visited[i-1][j]) q.push({i-1, j});
                if ((i+1 < rows) && !visited[i+1][j]) q.push({i+1, j});
                if ((j-1 >= 0) && !visited[i][j-1]) q.push({i, j-1});
                if ((j+1 < cols) && !visited[i][j+1]) q.push({i, j+1});
            }
        }
        return result;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int rows = grid.size();
        int cols = 0;
        if (rows > 0) cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (visited[i][j]) continue;
                if (grid[i][j] == '1') {
                    result += exploreIsland(i, j, grid, visited);
                } else {
                    visited[i][j] = true;
                }
            }
        }
        return result;
    }
};