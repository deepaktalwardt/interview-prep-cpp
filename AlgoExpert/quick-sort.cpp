#include <vector>
using namespace std;

void swap(int i, int j, vector<int>& array) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void quickSortHelper(vector<int>& array, int start, int end) {
	if (start >= end) return;
	int left = start + 1;
	int right = end;
	int pivot = array[start];
	while (right >= left) {
		int leftVal = array[left];
		int rightVal = array[right];
		if (leftVal > pivot && rightVal < pivot) {
			swap(left, right, array);
		}
		if (leftVal <= pivot) {
			left++;
		}
		if (rightVal >= pivot) {
			right--;
		}
	}
	swap(start, right, array);
	quickSortHelper(array, start, right - 1);
	quickSortHelper(array, right + 1, end);
}

vector<int> quickSort(vector<int> array) {
  // Write your code here.
	quickSortHelper(array, 0, array.size() - 1);
	return array;
}
