class Solution {
public:
    void visitNeighbors(int garden, vector<vector<int>>& graph, vector<int>& flowers) {
        vector<bool> colors(4, false);
		
		// Find all colors already assigned to neighbors
        for (int& n : graph[garden]) {
            if (flowers[n] != -1) {
                colors[flowers[n] - 1] = true;
            }
        }
		
		// Assign the first unassiged color to the current garden
        for (int i = 0; i < 4; i++) {
            if (!colors[i]) {
                flowers[garden] = i + 1;
                break;
            }
        }
    }
    
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> graph(N, vector<int>{});
        for (int i = 0; i < paths.size(); i++) {
            int to = paths[i][0];
            int from = paths[i][1];
            graph[to - 1].push_back(from - 1);
            graph[from - 1].push_back(to - 1);
        }
        vector<int> flowers(N, -1);
        for (int garden = 0; garden < N; garden++) {
		// Only visit neighbors of unvisited gardens
            if (flowers[garden] == -1) {
                visitNeighbors(garden, graph, flowers);
            }
        }
        return flowers;
    }
};