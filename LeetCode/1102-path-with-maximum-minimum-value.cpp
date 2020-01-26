#include <queue>
#include <vector>
using namespace std

// BFS + Priority Queue Solution -> Similar to Dijstra's 
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size();
        if (m == 0) return 0;
        int n = A[0].size();
        
        vector<vector<int>> diff = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};        
        using qtype = pair<int, pair<int, int>>;
            
        priority_queue<qtype, vector<qtype>, function<bool(qtype, qtype)>> 
            pq([](const qtype& v1, const qtype& v2) {
                return v1.first < v2.first;
            });
        
        pq.push({A[0][0], {0, 0}});
        while (!pq.empty()) {
            qtype curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            int w = curr.first;
            if (i == m - 1 && j == n - 1) {
                return w;
            }
            A[i][j] = -1;
            for (const auto& d : diff) {
                int x = i + d[0];
                int y = j + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && A[x][y] >= 0) {
                    pq.push({min(A[x][y], w), {x, y}});
                }
            }
        }
        return -1;
    }
};