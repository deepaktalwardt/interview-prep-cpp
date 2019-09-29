////////////////////////////////////////////////////////
// Time Complexity: O(N), Space Complexity: O(N)

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int minRewards(vector<int> scores) {
  // Write your code here.
	vector<int> rewards(scores.size(), 1);
	for (int i = 1; i < scores.size(); i++) {
		if (scores[i] > scores[i - 1]) {
			rewards[i] = rewards[i - 1] + 1;
		}
	}
	for (int k = scores.size() - 2; k >= 0; k--) {
		if (scores[k] > scores[k + 1]) {
			rewards[k] = max(rewards[k], rewards[k + 1] + 1);
		}
	}
	return accumulate(rewards.begin(), rewards.end(), 0);
}


////////////////////////////////////////////////////////
// Time Complexity: O(N), Space Complexity: O(N)

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

vector<int> findValleys(vector<int>& scores) {
	if (scores.size() == 1) return {0};
	vector<int> result;
	for (int i = 0; i < scores.size(); i++) {
		if (i == 0 && scores[i] < scores[i + 1]) {
				result.push_back(i);
			}
		if (i == scores.size() - 1 && scores[i] < scores[i - 1]) {
			result.push_back(i);
		}
		if (i == 0 || i == scores.size() - 1) continue;
		if (scores[i] < scores[i-1] && scores[i] < scores[i+1]) {
			result.push_back(i);
		}
	}
	return result;
}

int minRewards(vector<int> scores) {
  // Write your code here.
	vector<int> valleys = findValleys(scores);
	vector<int> rewards(scores.size(), 1);
	for (int v : valleys) {
		int left = v - 1;
		int right = v + 1;
		while (left >= 0 && scores[left] > scores[left + 1]) {
			rewards[left] = max(rewards[left], rewards[left + 1] + 1);
			left--;
		}
		while (right < scores.size() && scores[right] > scores[right - 1]) {
			rewards[right] = max(rewards[right], rewards[right - 1] + 1);
			right++;
		}
	}
	return accumulate(rewards.begin(), rewards.end(), 0);
}

////////////////////////////////////////////////////////
// Time Complexity: O(N^2), Space Complexity: O(N)

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int minRewards(vector<int> scores) {
  // Write your code here.
	vector<int> rewards(scores.size(), 1);
	for (int i = 1; i < scores.size(); i++) {
		int j = i - 1;
		if (scores[i] > scores[j]) {
			rewards[i] = rewards[j] + 1;
		} else {
			while (j >= 0 && scores[j] > scores[j + 1]) {
				rewards[j] = max(rewards[j], rewards[j + 1] + 1);
				j--;
			}
		}
	}
	return accumulate(rewards.begin(), rewards.end(), 0);
}