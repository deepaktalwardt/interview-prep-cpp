#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  // Write your code here.
	int maxPrev = array[0];
	int result = array[0];
	for (int i = 1; i < array.size(); i++) {
			int curr = max(array[i], array[i] + maxPrev);
			result = max(result, curr);
			maxPrev = curr;
	}
	return result;
}