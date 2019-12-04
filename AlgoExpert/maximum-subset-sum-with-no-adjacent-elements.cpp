// Time: O(N), Space O(1)
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  // Write your code here.
	if (array.size() == 0) return 0;
	if (array.size() == 1) return array[0];
	int maxSumPrevPrev = array[0];
	int maxSumPrev = max(maxSumPrevPrev, array[1]);
	for (int i = 2; i < array.size(); i++) {
		int curr = max(maxSumPrev, maxSumPrevPrev + array[i]);
		maxSumPrevPrev = maxSumPrev;
		maxSumPrev = curr;
	}
	return maxSumPrev;
}

// Time: O(N), Space O(N)
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  // Write your code here.
	if (array.size() == 0) return 0;
	if (array.size() == 1) return array[0];
	
	vector<int> maxSums(array.size(), 0);
	maxSums[0] = array[0];
	maxSums[1] = max(maxSums[0], array[1]);
	for (int i = 2; i < array.size(); i++) {
		maxSums[i] = max(maxSums[i - 1], maxSums[i - 2] + array[i]);
	}
	return maxSums[maxSums.size() - 1];
}
