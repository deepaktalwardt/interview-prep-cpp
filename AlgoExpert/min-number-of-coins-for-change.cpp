#include <vector>
#include <limits>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  // Write your code here.
	vector<int> minCoins(n + 1, numeric_limits<int>::max());
	minCoins[0] = 0;
	for (int d : denoms) {
		for (int amt = 0; amt < minCoins.size(); amt++) {
			if (d <= amt) {
				int toCompare = minCoins[amt - d] == numeric_limits<int>::max() ? minCoins[amt - d] : minCoins[amt - d] + 1;
				minCoins[amt] = min(toCompare, minCoins[amt]); 
			}
		}
	}
	return minCoins[minCoins.size() - 1] != numeric_limits<int>::max() ? minCoins[minCoins.size() - 1] : -1;
}
