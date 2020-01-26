class Solution {
private:
    int connectedComponents;
    vector<int> parent;
    int totalCost;
public:
    void init(int N) {
        connectedComponents = N;
        totalCost = 0;
        for (int i = 0; i < N + 1; i++) {
            parent.push_back(-1);
        }
    }
    
    int findParent(int x) {
        if (parent[x] < 0) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void unite(const vector<int> conn) {
        int c1 = conn[0];
        int c2 = conn[1];
        int cost = conn[2];
        int p1 = findParent(c1);
        int p2 = findParent(c2);
        if (p1 != p2) {
            int r1 = parent[p1];
            int r2 = parent[p2];
            if (r1 < r2) { // Remember ranks are -ve so the effect is opposite
                parent[p2] = p1;
            } else {
                parent[p1] = p2;
                if (r1 == r2) {
                    parent[p2]--;
                }
            }
            connectedComponents--;
            totalCost += cost;
        }
    }
    
    int minimumCost(int N, vector<vector<int>>& connections) {
        init(N);
        sort(connections.begin(), connections.end(), 
            [](const vector<int>& v1, const vector<int>& v2) {
                return v1[2] < v2[2];
            });
        for (const vector<int>& c : connections) {
            unite(c);
            if (connectedComponents == 1) {
                return totalCost;
            }
        }
        return connectedComponents == 1 ? totalCost : -1;
    }
};