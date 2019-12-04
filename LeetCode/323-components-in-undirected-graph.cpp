#include <unordered_map>
#include <queue>

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            graph[i] = {};
            visited[i] = false;
        }
        for (vector<int> v : edges) {
            int from = v[0];
            int to = v[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        int result = 0;
        int numVisited = 0;
        
        auto it = graph.begin();
        
        while (numVisited < n) {
            int node = it->first;
            if (!visited[node]) {
                queue<int> q;
                q.emplace(node);
                while (!q.empty()) {
                    int currNode = q.front();
                    q.pop();
                    visited[currNode] = true;
                    numVisited++;
                    for (int neighbor : it->second) {
                        if (!visited[neighbor]) {
                            q.emplace(neighbor);
                        }
                    }
                }
                result++;
            }
            it++;
        }
        return result;
    }
};