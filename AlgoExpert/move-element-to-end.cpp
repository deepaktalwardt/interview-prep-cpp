#include <vector>

using namespace std;
void swap(vector<int>& arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
	int left = 0; 
	int right = array.size() - 1;
	while (left < right) {
		if (array[left] != toMove) {
			left++;
			continue;
		}
		if (array[right] == toMove) {
			right--;
			continue;
		}
		swap(array, left, right);
		left++;
		right--;
	}
  return array;
}
