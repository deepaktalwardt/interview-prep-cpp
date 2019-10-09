class Solution {
public:
    void dfs(int u, int parent, vector<int>& ids, vector<bool>& visited, vector<int>& low, vector<vector<int>>& graph, vector<vector<int>>& result) {
        visited[u] = true;
        int id = ids[parent] + 1;
        low[u] = id;
        ids[u] = id;
        for (int n : graph[u]) {
            if (n == parent) continue;
            if (!visited[n]) {
                dfs(n, u, ids, visited, low, graph, result);
                low[u] = min(low[u], low[n]);
                if (ids[u] < low[n]) {
                    result.push_back({u, n});
                }
            } else {
                low[u] = min(low[u], ids[n]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>());
         for (const vector<int>& conn : connections) {
            int to = conn[0];
            int from = conn[1];
            graph[to].push_back(from);
            graph[from].push_back(to);
        }
        
        vector<vector<int>> result;
        vector<bool> visited(n, false);
        vector<int> low(n, -1);
        vector<int> ids(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, i, ids, visited, low, graph, result);
            }
        }
        return result;
    }
};