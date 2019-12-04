#include <vector>
#include <iostream>
using namespace std;

int findCorrectSpot(int elem, bool fromFront, vector<int>& array) {
	int result;
	if (fromFront) {
		for (int i = 0; i < array.size(); i++) {
			if (elem < array[i]) {
				result = i;
				break;
			}
		}
	} else {
		for (int k = array.size() - 1; k >= 0; k--) {
			if (elem > array[k]) {
				result = k;
				break;
			}
		}
	}
	return result;
}

vector<int> subarraySort(vector<int> array) {
  // Write your code here.
	int smallU = INT_MAX;
	int largeU = INT_MIN;
	
	vector<int> result = {-1, -1};
	
	for (int i = 0; i < array.size(); i++) {
		if (i == 0) {
			if (array[i] > array[i+1]) {
				if (smallU > array[i]) smallU = array[i];
				if (largeU < array[i]) largeU = array[i];
			}
		}
		if (i > 0 && i < array.size() - 1) {
			if (array[i] > array[i+1] || array[i] < array[i-1]) {
				if (smallU > array[i]) smallU = array[i];
				if (largeU < array[i]) largeU = array[i];
			}
		}
		if (i == array.size() - 1) {
			if (array[i] < array[i-1]) {
				if (smallU > array[i]) smallU = array[i];
				if (largeU < array[i]) largeU = array[i];
			}
		}
	}
	if (smallU == INT_MAX && largeU == INT_MIN) return {-1, -1};
	int left = findCorrectSpot(smallU, true, array);
	int right = findCorrectSpot(largeU, false, array);
	cout << left << ", " << right << endl;
	return {left, right};
}
