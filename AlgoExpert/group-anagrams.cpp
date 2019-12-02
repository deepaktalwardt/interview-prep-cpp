#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
  // Write your code here.
	unordered_map<string, vector<int>> wordsMap;
	vector<string> sortedWords;
	for (auto& w : words) {
		string sw = w;
		sort(sw.begin(), sw.end());
		sortedWords.push_back(sw);
	}
	
	for (int i = 0; i < words.size(); i++) {
		string w = sortedWords[i];
		auto it = wordsMap.find(w);
		if (it != wordsMap.end()) {
			(it->second).push_back(i);
		} else {
			wordsMap[w] = {i};
		}
	}
	
	vector<vector<string>> result;
	for (auto it = wordsMap.begin(); it != wordsMap.end(); it++) {
		vector<int> indices = it->second;
		vector<string> row;
		for (auto& idx : indices) {
			row.push_back(words[idx]);
		}
		result.push_back(row);
	}
	return result;
}
