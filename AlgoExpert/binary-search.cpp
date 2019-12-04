#include <vector>
using namespace std;

int binarySearchHelper(vector<int> array, int left, int right, int target) {
	if (left > right) {
		return -1;
	}
	int mid = (left + right) / 2;
	if (array[mid] == target) {
		return mid;
	} else if (target < array[mid]) {
		return binarySearchHelper(array, 0, mid - 1, target);
	} else {
		return binarySearchHelper(array, mid + 1, right, target);
	}
}

int binarySearch(vector<int> array, int target) {
  // Write your code here.
	return binarySearchHelper(array, 0, array.size() - 1, target);
}