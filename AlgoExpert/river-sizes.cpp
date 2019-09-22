#include <vector>
#include <queue>
using namespace std;

int findSizeOfRiver(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& visited) {
	int sizeOfRiver = 0;
	int rows = matrix.size();
	int cols = matrix[0].size();
	queue<vector<int>> q;
	q.push({i, j});
	while (!q.empty()) {
		vector<int> front = q.front();
		q.pop();
		if (visited[front[0]][front[1]]) continue;
		visited[front[0]][front[1]] = 1;
		if (matrix[front[0]][front[1]]) {
			sizeOfRiver++;
			if ((front[0]-1 >= 0) && !visited[front[0]-1][front[1]]) q.push({front[0]-1, front[1]});
			if ((front[0]+1 < rows) && !visited[front[0]+1][front[1]]) q.push({front[0]+1, front[1]});
			if ((front[1]-1 >= 0) && !visited[front[0]][front[1]-1]) q.push({front[0], front[1]-1});
			if ((front[1]+1 < cols) && !visited[front[0]][front[1]+1]) q.push({front[0], front[1]+1});
		}
	}
	return sizeOfRiver;
}

vector<int> riverSizes(vector<vector<int> > matrix) {
  // Write your code here.
	vector<int> result;
	vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (visited[i][j]) continue;
			if (matrix[i][j] == 1) {
				int s = findSizeOfRiver(i, j, matrix, visited);
				result.push_back(s);
			} else {
				visited[i][j] = 1;
			}
		}
	}
	return result;
}
