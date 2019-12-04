#include <queue>
#include <unordered_map>

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        queue<int> q;
        unordered_map<int, int> depth;
        int numFresh = 0;
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 2) {
                    int code = c + r * C;
                    q.push(code);
                    depth[code] = 0;
                } else if (grid[r][c] == 1) {
                    numFresh++;
                }
            }
        }
        
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};
        int maxDepth = 0;
        int newlyRotten = 0;
        
        while (!q.empty()) {
            int elem = q.front();
            q.pop();
            int r = elem / C;
            int c = elem % C;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1) {
                    int ncode = nc + nr * C;
                    q.push(ncode);
                    grid[nr][nc] = 2;
                    newlyRotten++;
                    int ndepth = depth.find(elem)->second + 1;
                    depth[ncode] = ndepth;
                    if (ndepth > maxDepth) {
                        maxDepth = ndepth;
                    }
                }
            }
        }
        if (newlyRotten < numFresh) return -1;
        return maxDepth;
    }
};