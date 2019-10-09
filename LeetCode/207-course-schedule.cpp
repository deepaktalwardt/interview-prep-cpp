#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool dfs(int i, vector<bool>& visited, unordered_set<int>& visiting, unordered_map<int, vector<int>>& graph) {
        if (visiting.find(i) != visiting.end()) return false;
        visiting.emplace(i);
        for (int n : graph[i]) {
            if (!visited[i]) {
                bool finishPossible = dfs(n, visited, visiting, graph);
                if (!finishPossible) return false;
            }
        }
        visited[i] = true;
        visiting.erase(i);
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (const vector<int>& prereq : prerequisites) {
            auto it = graph.find(prereq[0]);
            if (it != graph.end()) {
                (it->second).push_back(prereq[1]);
            } else {
                graph[prereq[0]] = {prereq[1]};
            }
        }
        
        vector<bool> visited(numCourses, false);
        unordered_set<int> visiting;
        
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                bool finishPossible = dfs(i, visited, visiting, graph);
                if (!finishPossible) return false;
            }
        }
        return true;
    }
};