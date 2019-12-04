#include <vector>
#include <unordered_map>
using namespace std;

vector<int> largestRange(vector<int> array) {
  // Write your code here.
	int longest = 0;
	vector<int> longestRange;
	unordered_map<int, bool> nums;
	for (int n : array) {
		nums[n] = true;
	}
	
	for (int n : array) {
		if (!nums[n]) continue;
		nums[n] = false;
		int len = 1;
		int left = n - 1;
		int right = n + 1;
		while (nums[left]) {
			left--;
			len++;
		}
		while (nums[right]) {
			right++;
			len++;
		}
		if (longest < len) {
			longest = len;
			longestRange = {left + 1, right - 1};
		}
	}
	return longestRange;
}
