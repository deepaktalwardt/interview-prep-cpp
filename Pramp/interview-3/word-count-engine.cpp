#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <unordered_map>
#include <map>

using namespace std;

vector<string> allWords(const string& document ) {
  vector<string> words;
  string word;
  for (char c : document) {
    if (ispunct(c)) continue;
    if (isalpha(c)) {
      word += tolower(c);
    } else if (c == ' ' && word != "") {
      words.push_back(word);
      word = "";
    }
  }
  if (word != "") words.push_back(word);
  return words;
}


vector<vector<string>> wordCountEngine( const string& document ) 
{
  // your code goes here
  vector<string> words = allWords(document);
  unordered_map<string, pair<int, int>> m;
  int i = 0;
  for (string w : words) {
    auto it = m.find(w);
    if (it != m.end()) {
      (it->second).first++;
    } else {
      m[w] = pair<int, int> (1, i);
    }
    i++;
  }
  
  multimap<pair<int, int>, string, function<bool (pair<int, int>, pair<int, int>)>> 
    m2([](const pair<int, int> a, const pair<int, int> b) {
    if (a.first == b.first) {
      return a.second < b.second;
    }
    return a.first > b.first;
  });
  
  for (auto it = m.begin(); it != m.end(); it++) {
    pair<int, int> f((it->second).first, (it->second).second);
    string w = it->first;
    m2.insert({f, w});
  }

  vector<vector<string>> result;
  for (auto it = m2.begin(); it != m2.end(); it++) {
    vector<string> wordAndCount;
    wordAndCount.push_back(it->second);
    wordAndCount.push_back(to_string((it->first).first));
    result.push_back(wordAndCount);
  }
  return result;
}

int main() {
  
  string data = "Practice makes perfect. you'll only get Perfect by practice. just practice!";
  vector<vector<string>> words = wordCountEngine(data);
  
  for (vector<string> w : words) {
    for (string s : w) {
      cout << s;
    }
    cout << endl;
  }
  
  return 0;
}