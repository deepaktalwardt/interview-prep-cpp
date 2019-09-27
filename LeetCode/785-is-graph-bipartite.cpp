#include <queue>
#include <vector>

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool isCurrSetA = true;
        vector<int> visited(graph.size(), -1); // -1 : not visited, 0 : blue color, 1 : red color
        int currColor;
        for (int i = 0; i < graph.size(); i++) {
            if (visited[i] == -1) {
                queue<int> q;
                q.push(i);
                visited[i] = 0;
                while (!q.empty()) {
                    int front = q.front();
                    q.pop();
                    currColor = visited[front];
                    for (int child : graph[front]) {
                        if (visited[child] == currColor) return false;
                        if (visited[child] == -1) {
                            q.push(child);
                            visited[child] = 1 - currColor;
                        }
                    }
                }
            }
        }
        return true;
    }
};
