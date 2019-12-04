// Solution 2 (Better)
#include <vector>
using namespace std;

void swap(vector<int>& array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void helper(int i, vector<int>& array, vector<vector<int>>& perms) {
	if (i == array.size() - 1) {
		vector<int> onePerm = array;
		perms.push_back(onePerm);
	} else {
		for (int j = i; j < array.size(); j++) {
			swap(array, i, j);
			helper(i + 1, array, perms);
			swap(array, i, j);
		}
	}
}

vector<vector<int>> getPermutations(vector<int> array) {
  // Write your code here.
	if (array.size() == 0) return {};
	vector<vector<int>> result;
	helper(0, array, result);
	return result;
}


// Solution 1 (Worse)
// Time: O(N^2 * N!), Space: O(N * N!)
#include <vector>
using namespace std;

vector<int> removeFromArray(vector<int> array, int i) {
	vector<int> removedArray = array;
	removedArray.erase(removedArray.begin() + i);
	return removedArray;
}

void helper(vector<int> array, vector<int> perm, vector<vector<int>>& perms) {
	if (array.size() == 0) {
		perms.push_back(perm);
	} else {
		for (int i = 0; i < array.size(); i++) {
			vector<int> arrayRemoved = removeFromArray(array, i);
			vector<int> newPerm = perm;
			newPerm.push_back(array[i]);
			helper(arrayRemoved, newPerm, perms);
		}
	}
}

vector<vector<int>> getPermutations(vector<int> array) {
  // Write your code here.
	if (array.size() == 0) return {};
	vector<vector<int>> result;
	helper(array, {}, result);
	return result;
}
