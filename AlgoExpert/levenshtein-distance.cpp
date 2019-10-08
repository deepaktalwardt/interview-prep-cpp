#include <iostream>
#include <vector>

using namespace std;

int levenshteinDistance(string str1, string str2) {
  // Write your code here.
	vector<vector<int>> E(str1.size() + 1, vector<int>(str2.size() + 1, INT_MAX));
	for (int i = 0; i < str2.size() + 1; i++) {
		E[0][i] = i;
	}
	for (int i = 1; i < str1.size() + 1; i++) {
		E[i][0] = i;
	}
	for (int r = 1; r < str1.size() + 1; r++) {
		for (int c = 1; c < str2.size() + 1; c++) {
			if (str1[r - 1] == str2[c - 1]) {
				E[r][c] = E[r - 1][c - 1];
			} else {
				E[r][c] = 1 + min(E[r - 1][c - 1], min(E[r - 1][c], E[r][c - 1]));
			}
		}
	}
	return E[str1.size()][str2.size()];
}