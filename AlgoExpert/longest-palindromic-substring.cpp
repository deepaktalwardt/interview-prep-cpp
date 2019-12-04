using namespace std;

vector<int> getLongestPalindromeBetween(const string& str, int i, int j) {
	while (i >= 0 && j < str.size()) {
		if (str[i] != str[j]) {
			break;
		}
		i--;
		j++;
	}
	return vector<int> {i+1, j};
}

string longestPalindromicSubstring(string str) {
  // Write your code here.
	string result = "";
	for (int i = 0; i < str.size(); i++) {
		vector<int> odd = getLongestPalindromeBetween(str, i-1, i+1);
		vector<int> even = getLongestPalindromeBetween(str, i-1, i);
		vector<int> longer = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
		if (result.size() < longer[1] - longer[0]) {
			result = str.substr(longer[0], longer[1] - longer[0]);
		}
	}
	return result;
}