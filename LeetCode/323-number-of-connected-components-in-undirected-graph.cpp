class Solution {
public:
    int connectedComponents;
    vector<int> parent;
    
    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return find(parent[node]);
    }
    
    void unite(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        int m = min(parentX, parentY);
        parent[x] = m;
        parent[y] = m;
        parent[parentX] = m;
        parent[parentY] = m;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        connectedComponents = 0;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        for (auto& e : edges) {
            unite(e[0], e[1]);
        }
        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                connectedComponents++;
            }
        }
        return connectedComponents;
    }
};