#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int> > fourNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	unordered_map<int, vector<vector<int>>> m;
	vector<vector<int>> result;
	
	for (int c1 = 0; c1 < array.size(); c1++) {
		for (int c2 = c1+1; c2 < array.size(); c2++) {
			int comp = targetSum - (array[c1] + array[c2]);
			auto it = m.find(comp);
			if (it != m.end()) {
				vector<vector<int>> doubles = it->second;
				for (vector<int> d : doubles) {
					d.push_back(array[c1]); d.push_back(array[c2]);
					result.push_back(d);
				}
			}
		}
		for (int c3 = 0; c3 < c1; c3++) {
			int sum = array[c1] + array[c3];
			auto it = m.find(sum);
			if (it != m.end()) {
				(it->second).push_back({array[c1], array[c3]});
			} else {
				m[sum] = {{array[c1], array[c3]}};
			}
		}
	}
	return result;
}