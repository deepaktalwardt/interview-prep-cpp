#include <iostream>
#include <vector>

using namespace std;

int findBusiestPeriod( const vector<vector<int> >& data ) 
{
  // your code goes here
  int people = 0;
  int maxTime = 0;
  int maxPeople = 0;
  
  for (int i = 0; i < data.size(); i++) {
    vector<int> elem = data[i];
    if (elem[2] == 0) {
      people -= elem[1];
    } else if (elem[2] == 1) {
      people += elem[1];
    }
    if (i+1 < data.size() && data[i+1][0] == elem[0]) {
      continue;
    }
    if (people > maxPeople) {
      maxPeople = people;
      maxTime = elem[0];
    }
  }
  return maxTime;
}

int main() {
  
  vector<vector<int>> data;
  data.push_back({1487799425, 14, 1});
  data.push_back({1487799425, 4,  0});
  data.push_back({1487799425, 2,  0});
  data.push_back({1487800378, 10, 1});
  data.push_back({1487801478, 18, 0});
  data.push_back({1487801478, 18, 1});
  data.push_back({1487901013, 1,  0});
  
  cout << (findBusiestPeriod(data)) << endl;
  
  return 0;
}