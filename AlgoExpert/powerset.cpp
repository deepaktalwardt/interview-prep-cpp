#include <vector>
using namespace std;

vector<vector<int> > powerset(vector<int> array) {
  // Write your code here.
	vector<vector<int>> result = {{}};
	for (int& elem : array) {
		int rSize = result.size();
		for (int i = 0; i < rSize; i++) {
			vector<int> v = result[i];
			v.push_back(elem);
			result.push_back(v);
		}
	}
	return result;
}