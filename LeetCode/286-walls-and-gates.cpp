class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0) return;
        int n = rooms[0].size();
        
        vector<vector<int>> diff = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }
        int steps = 0;
        while (!q.empty()) {
            int layerSize = q.size();
            while (layerSize--) {
                pair<int, int> curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                rooms[i][j] = steps;
                for (auto& d : diff) {
                    int newi = i + d[0];
                    int newj = j + d[1];
                    if (newi >= 0 && newi < m && newj >= 0 && newj < n && rooms[newi][newj] == INT_MAX) {
                        rooms[newi][newj] = min(rooms[newi][newj], steps);
                        q.emplace(newi, newj);
                    }
                }
            }
            steps++;
        }
    }
};