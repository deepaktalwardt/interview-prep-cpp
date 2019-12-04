#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> buildSeq(vector<int>& array, vector<int>& seq, int maxId, int maxSum) {
	vector<vector<int>> result = {{}, {}};
	result[0].push_back(maxSum);
	while (maxId != INT_MIN) {
		result[1].insert(result[1].begin(), array[maxId]);
		maxId = seq[maxId];
	}
	return result;
}

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  // Write your code here.
	vector<int> sums = array;
	vector<int> seq(array.size(), INT_MIN);
	int maxId = 0;
	for (int i = 0; i < array.size(); i++) {
		int curr = array[i];
		for (int j = 0; j < i; j++) {
			if (array[j] < array[i] && sums[j] + array[i] >= sums[i]) {
				sums[i] = array[i] + sums[j];
				seq[i] = j;
			}
		}
		if (sums[i] >= sums[maxId]) {
			maxId = i;
		}
	}
	return buildSeq(array, seq, maxId, sums[maxId]);
}
