#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
	vector<int> result;
	sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	int numOne, numTwo;
	int minSoFar = numeric_limits<int>::max();
	int i = 0;
	int j = 0;
	int currDiff = numeric_limits<int>::max();
	while (i < arrayOne.size() && j < arrayTwo.size()) {
		numOne = arrayOne[i];
		numTwo = arrayTwo[j];
		if (numOne < numTwo) {
			currDiff = numTwo - numOne;
			i++;
		} else if (numOne > numTwo) {
			currDiff = numOne - numTwo;
			j++;
		} else {
			result = {numOne, numTwo};
			return result;
		}
		if (currDiff < minSoFar) {
			minSoFar = currDiff;
			result = {numOne, numTwo};
		}
	}
	return result;
}