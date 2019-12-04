#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Dynamic programming O(N) time, O(N) space
int decodeVariations(const string& S) {
	// your code goes here
  int n = S.length();
  vector<int> result(n+1, 0);
  result[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (S[i] == '0') {
      result[i] = 0;
    } else if (S[i] == '1') {
      result[i] = result[i+1] + result[i+2];
    } else if (S[i] == '2') {
      result[i] = result[i+1];
      if (i != n - 1 && S[i+1] < '7') {
        result[i] += result[i+2];
      }
    } else {
      result[i] = result[i+1];
    }
  }
  return result[0];
}
