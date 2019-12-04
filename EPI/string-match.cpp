#include <string>
#include "test_framework/generic_test.h"
#include <unordered_set>
using std::string;

// Returns the index of the first character of the substring if found, -1
// otherwise.
int RabinKarp(const string &t, const string &s) {
  // TODO - you fill in here.
  int k = s.size();
  int n = t.size();
  std::unordered_set<string> stringSet;
  stringSet.emplace(s);
  for (int i = 0; i < n - k + 1; i++) {
      string toCheck = t.substr(i, k);
      if (stringSet.find(toCheck) != stringSet.end()) {
          return i;
      }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"t", "s"};
  return GenericTestMain(args, "substring_match.cc", "substring_match.tsv",
                         &RabinKarp, DefaultComparator{}, param_names);
}
