#include <unordered_map>
using namespace std;

string longestSubstringWithoutDuplication(string str) {
  // Write your code here.
	int n = str.size();
	if (n <= 1) return str; 
	
	int maxLen = 0;
	int maxStartIdx = -1;
	unordered_map<char, int> lastSeenAt;
	
	int startIdx = 0;
	
	for (int i = 0; i < n; i++) {
		char curr = str[i];
		if (lastSeenAt.find(curr) != lastSeenAt.end()) {
			startIdx = max(startIdx, lastSeenAt[curr] + 1);
		}
		if (maxLen < i - startIdx + 1) {
			maxLen = i - startIdx + 1;
			maxStartIdx = startIdx;
		}
		lastSeenAt[curr] = i;
	}
	string result = str.substr(maxStartIdx, maxLen);
	return result;
}
