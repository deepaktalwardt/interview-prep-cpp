#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	sort(array.begin(), array.end());
	int curr = 0;
	
	vector<vector<int>> result = {};
	
	while (curr != array.size()-2) {
		int left = curr + 1;
		int right = array.size() - 1;
		while (left < right) {
			int sum = array[curr] + array[left] + array[right];
			if (sum < targetSum) {
				left++;
			} else if (sum > targetSum) {
				right--;
			} else {
				result.push_back({array[curr], array[left], array[right]});
				left++;
				right--;
			}
		}
		curr++;
	}
	return result;
}