#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getDifferentNumber(const vector<int>& arr2 ) 
{
  // your code goes here
  vector<int> arr = arr2;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size() + 1; i++) {
    if (i < arr.size()) {
      if (i != arr[i]) {
        return i;
      }
    } else {
      return i;
    }
  }
}

int main() {
  vector<int> test1 = {4, 5, 1, 2}; // Answer: 0
  vector<int> test2 = {-4, -5, -1, 2, 0}; // Answer: 3
  vector<int> test3 = {0, 1, 2, 3, 1000}; // Answer: 4
  
  cout << (getDifferentNumber(test1)) << endl;
  cout << (getDifferentNumber(test2)) << endl;
  cout << (getDifferentNumber(test3)) << endl;
  
  return 0;
}