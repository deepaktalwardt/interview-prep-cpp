#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iostream>

using namespace std;

bool dfs(int start, unordered_map<int, vector<int>>& graph, vector<int>& order, unordered_set<int>& visited, unordered_set<int>& visiting) {
	if (visited.find(start) != visited.end()) return false;
	if (visiting.find(start) != visiting.end()) return true;
	visiting.emplace(start);
	for (int& prereq : graph[start]) {
		bool containsCycle = dfs(prereq, graph, order, visited, visiting);
		if (containsCycle) return true;
	}
	visited.emplace(start);
	visiting.erase(start);
	order.push_back(start);
	return false;
}

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
  // Write your code here.
	unordered_map<int, vector<int>> graph;
	for (const vector<int>& d : deps) {
		auto it = graph.find(d[1]);
		if (it != graph.end()) {
			(it->second).push_back(d[0]);
		} else {
			graph[d[1]] = {d[0]};
		}
	}
	unordered_set<int> visited;
	unordered_set<int> visiting;
	vector<int> order;
	for (int& j : jobs) {
		bool containsCycle = dfs(j, graph, order, visited, visiting);
		if (containsCycle) return {};
	}
	return order;
}

