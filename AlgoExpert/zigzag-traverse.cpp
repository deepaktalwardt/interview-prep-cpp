#include <vector>
#include <iostream>

using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> array) {
  // Write your code here.
	bool goingDown = true;
	int rows = array.size();
	int cols = array[0].size();
	int r = 0;
	int c = 0;
	vector<int> result;
	while (r < rows && c < cols) {
		result.push_back(array[r][c]);
		if (goingDown) {
			if (c == 0 && r != rows-1) {
				r++;
				goingDown = false;
			} else if (r == rows-1) {
				c++;
				goingDown = false;
			} else {
				r++;
				c--;
			}
		} else {
			if (r == 0 && c != cols-1) {
				c++;
				goingDown = true;
			} else if (c == cols-1) {
				r++;
				goingDown = true;
			} else {
				r--;
				c++;
			}
		}
	}
	return result;
}
		