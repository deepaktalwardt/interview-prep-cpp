#include <vector>

using namespace std;

vector<int> buildPattern(string str) {
	int n = str.size();
	if (n == 1) return {-1};
	int i = 1;
	int j = 0;
	vector<int> pattern(n, -1);
	while (i < n) {
		if (str[i] == str[j]) {
			pattern[i] = j;
			i++;
			j++;
		} else {
			if (j != 0) {
				j = pattern[j - 1] + 1;
			} else {
				i++;
			}
		}
	}
	return pattern;
}

bool doesMatch(string str, string substr, vector<int>& pattern) {
	int i = 0;
	int j = 0;
	while (i + substr.size() - j <= str.size()) {
		if (str[i] == substr[j]) {
			if (j == substr.size() - 1) return true;
			i++;
			j++;
		} else {
			if (j != 0) {
				j = pattern[j - 1] + 1;
			} else {
				i++;
			}
		}
	}
	return false;
}

bool knuthMorrisPrattAlgorithm(string str, string substr) {
  // Write your code here.
  vector<int> pattern = buildPattern(substr);
	return doesMatch(str, substr, pattern);
}
