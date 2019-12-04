#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> buildArray(vector<vector<int>>& values, vector<vector<int>>& items, int maxValue) {
	vector<vector<int>> result = {{}, {}};
	result[0].push_back(maxValue);
	int j = values[0].size() - 1;
	for (int i = values.size() - 1; i > 0; i--) {
		if (values[i][j] > values[i - 1][j]) {
			result[1].insert(result[1].begin(), i - 1);
			j -= items[i - 1][1];
		}
		if (j == 0) break;
	}
	return result;
}

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
  // Write your code here.
	vector<vector<int>> values(items.size() + 1, vector<int>(capacity + 1, 0));
	for (int i = 1; i < items.size() + 1; i++) {
		int currValue = items[i - 1][0];
		int currWeight = items[i - 1][1];
		for (int j = 1; j < capacity + 1; j++) {
			int currCapacity = j;
			if (currWeight > currCapacity) {
				values[i][j] = values[i-1][j];
			} else {
				values[i][j] = max(values[i - 1][j], currValue + values[i - 1][j - currWeight]);
			}
		}
	}
	return buildArray(values, items, values[items.size()][capacity]);
}
