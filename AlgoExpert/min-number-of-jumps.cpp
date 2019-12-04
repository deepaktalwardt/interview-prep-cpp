#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
  // Write your code here.
	int n = array.size();
	if (n == 1) return 0;
	int jumps = 0;
	int maxReach = array[0];
	int steps = array[0];
	for (int i = 1; i < n - 1; i++) {
		maxReach = max(maxReach, array[i] + i);
		steps--;
		if (steps == 0) {
			jumps++;
			steps = maxReach - i;
		}
	}
	return jumps + 1;
}