// Naive Solution 
// Time: O(N^3) | Space: O(N^2)
#include <vector>
using namespace std;

bool isPalindrome(const string& str) {
	int n = str.size();
	int i = 0, j = n - 1;
	while (i < j) {
		if (str[i] == str[j]) {
			i++;
			j--;
		} else {
			return false;
		}
	}
	return true;
}

int palindromePartitioningMinCuts(string str) {
  // Write your code here.
	int n = str.size();
	vector<vector<bool> > pals(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
				pals[i][j] = isPalindrome(str.substr(i, j - i + 1));
		}
	}
	
	vector<int> minCuts(n, INT_MAX);
	
	for (int i = 0; i < n; i++) {
		if (pals[0][i]) {
			minCuts[i] = 0;
		} else {
			minCuts[i] = minCuts[i - 1] + 1;
			for (int j = 1; j < i; j++) {
				if (pals[j][i] && minCuts[j - 1] + 1 < minCuts[i]) {
					minCuts[i] = minCuts[j - 1] + 1;
				}
			}
		}
	}
  return minCuts[n - 1];
}