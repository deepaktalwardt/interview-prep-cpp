#include <vector>
using namespace std;

// Time: O(NM * min(N, M))
// Space: O(NM * min(N, M))
vector<char> longestCommonSubsequence(string str1, string str2) {
  // Write your code here.
	vector<vector<vector<char>>> LCSs;
	for (int i = 0; i < str2.size() + 1; i++) {
		LCSs.push_back(vector<vector<char>>());
		for (int j = 0; j < str1.size() + 1; j++) {
			LCSs[i].push_back(vector<char>());
		}
	}
	for (int i = 1; i < str2.size() + 1; i++) {
		for (int j = 1; j < str1.size() + 1; j++) {
			if (str2[i - 1] == str1[j - 1]) {
				vector<char> toPut = LCSs[i - 1][j - 1];
				toPut.push_back(str2[i - 1]);
				LCSs[i][j] = toPut;
			} else {
				vector<char> top = LCSs[i - 1][j];
				vector<char> left = LCSs[i][j - 1];
				if (top.size() < left.size()) {
					LCSs[i][j] = LCSs[i][j - 1];
				} else {
					LCSs[i][j] = LCSs[i - 1][j];
				}
			}
		}
	}
	return LCSs[LCSs.size() - 1][LCSs[0].size() - 1];
}