#include <vector>
#include <iostream>
using namespace std;

int doBinarySearch(vector<int>& row, int target, int startIdx, int endIdx) {
	if (startIdx >= endIdx) return -1;
	int midIdx = (startIdx + endIdx) / 2;
	if (row[midIdx] == target) {
		return midIdx;
	} else if (row[midIdx] > target) {
		return doBinarySearch(row, target, startIdx, midIdx);
	} else {
		return doBinarySearch(row, target, startIdx + 1, endIdx);
	}
}

vector<int> searchInSortedMatrix(vector<vector<int> > matrix, int target) {
  // Write your code here.
	vector<int> result = {-1, -1};
	int rows = matrix.size();
	int cols = matrix[0].size();
	for (int i = 0; i < rows; i++) {
		vector<int> row = matrix[i];
		if (row[0] <= target && row[cols - 1] >= target) {
			int loc = doBinarySearch(row, target, 0, cols);
			if (loc != -1) {
				result = {i, loc};
				cout << result[0] << ", " << result[1] << endl;
				return result;
			}
		}
	}
	cout << result[0] << ", " << result[1] << endl;
	return result;
}
