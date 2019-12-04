class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<vector<int>> trustGraph(N, vector<int>());
        for (int i = 0; i < trust.size(); i++) {
            int from = trust[i][0];
            int to = trust[i][1];
            trustGraph[from - 1].push_back(to);
        }
        int candidate = -1;
        int numCandidates = 0;
        for (int i = 0; i < N; i++) {
            if (trustGraph[i].size() == 0) {
                candidate = i + 1;
                numCandidates++;
            }
        }
        if (numCandidates != 1) return -1;
        for (int i = 0; i < N; i++) {
            if (i == candidate - 1) continue;
            vector<int> conn = trustGraph[i];
            if (find(conn.begin(), conn.end(), candidate) == conn.end()) return -1;
        }
        return candidate;
    }
};