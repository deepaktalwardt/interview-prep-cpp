#include <vector>
#include <numeric>
using namespace std;

int waterArea(vector<int> heights) {
  // Write your code here.
	if (heights.size() <= 2) return 0;
	vector<int> leftMax(heights.size(), 0);
	vector<int> rightMax(heights.size(), 0);
	
	int leftMaxSoFar = 0;
	int rightMaxSoFar = 0;
	
	for (int i = 0; i < heights.size(); i++) {
		leftMax[i] = leftMaxSoFar;
		if (heights[i] > leftMaxSoFar) {
			leftMaxSoFar = heights[i];
		}
	}
	for (int j = heights.size() - 1; j >= 0; j--) {
		rightMax[j] = rightMaxSoFar;
		if (heights[j] > rightMaxSoFar) {
			rightMaxSoFar = heights[j];
		}
	}
	int waterLevel = 0;
	for (int k = 0; k < heights.size(); k++) {
		int minLevel = min(leftMax[k], rightMax[k]);
		if (heights[k] < minLevel) {
			waterLevel +=  minLevel - heights[k];
		}
	}
	return waterLevel;
}