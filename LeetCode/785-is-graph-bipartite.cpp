#include <queue>
#include <vector>

class Solution {
public:
    bool doBFS(int i, vector<int>& visited, vector<vector<int>>& graph) {
        queue<int> q;
        int currColor;
        q.push(i);
        visited[i] = 0; // Assign blue by default
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            currColor = visited[currNode];
            for (int child : graph[currNode]) {
                if (visited[child] == currColor) return false;
                if (visited[child] == -1) {
                    q.push(child);
                    visited[child] = 1 - currColor;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1); // -1 : not visited, 0 : blue color, 1 : red color
        for (int i = 0; i < graph.size(); i++) {
            if (visited[i] == -1) {
                if (!doBFS(i, visited, graph)) return false;
            }
        }
        return true;
    }
};