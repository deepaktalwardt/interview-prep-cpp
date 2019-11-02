#include <vector>
using namespace std;

int binarySearch(vector<int>& array, int target, int startIdx, int endIdx) {
	if (startIdx > endIdx) return -1;
	int mid = (startIdx + endIdx) / 2;
	if (target == array[mid]) {
		return mid;
	} else if (target < array[mid]) {
		return binarySearch(array, target, startIdx, mid - 1);
	} else {
		return binarySearch(array, target, mid + 1, endIdx);
	}
}

int shiftedBinarySearch(vector<int> array, int target) {
  // Write your code here.
	int n = array.size();
	int part = 0;
	
	while (part < n) {
		if (array[part - 1] > array[part]) {
			part--;
			break;
		}
		part++;
	}
	
	if (part == n) {
		return binarySearch(array, target, 0, n - 1);
	}
	
	if (target >= array[0] && target <= array[part]) {
		return binarySearch(array, target, 0, part);
	} else {
		return binarySearch(array, target, part, n - 1);
	}
	
}
