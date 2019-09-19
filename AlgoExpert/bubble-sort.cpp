#include <vector>
using namespace std;

void swap(int i, int j, vector<int>* array) {
	int temp = array->at(j);
	array->at(j) = array->at(i);
	array->at(i) = temp;
}

vector<int> bubbleSort(vector<int> array) {
  // Write your code here.
	if (array.empty()) return {};
	bool isSorted = false;
	int counter = 0;
	while (!isSorted) {
		isSorted = true;
		for (int i = 0; i < array.size() - 1 - counter; i++) {
			if (array[i] > array[i+1]) {
				swap(i, i+1, &array);
				isSorted = false;
			}
		}
		counter++;
	}
	return array;
}