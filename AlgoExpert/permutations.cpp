
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
