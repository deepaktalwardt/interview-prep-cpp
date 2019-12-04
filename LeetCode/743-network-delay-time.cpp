#include <unordered_map>
#include <queue>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<vector<int>>> graph;
        for (auto& t : times) {
            auto it = graph.find(t[0]);
            if (it != graph.end()) {
                (it->second).push_back({t[1], t[2]});
            } else {
                graph[t[0]] = {{t[1], t[2]}};
            }
        }
        int numVisited = 0;
        vector<int> delay(N + 1, -1);
        delay[K] = 0;
        
        queue<int> q;
        q.emplace(K);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto& n : graph[curr]) {
                if (delay[n[0]] == -1 || delay[n[0]] > delay[curr] + n[1]) {
                    delay[n[0]] = delay[curr] + n[1];
                    q.emplace(n[0]);
                }
            }
        }
        int maxDelay = INT_MIN;
        for (int i = 1; i <= N; i++) {
            if (delay[i] == -1) return -1;
            if (delay[i] > maxDelay) maxDelay = delay[i];
        }
        return maxDelay;
    }
};