#include <iostream>
#include <vector>

using namespace std;

// arr1 = [1, 2, 3, 5, 6, 20, 100], arr2 = [3, 6, 7, 8, 20]
//        Scenario 1: M ~= N
//         Time: O(M + N)
//         Space: O(1)

//        Scenario 2: M >> N
//         Time: O(N log M)
//         Space: O(1)

bool binarySearch(int i, const vector<int>& arr, int left, int right) {
  if (left > right) return false;
  int middle = left + ((right - left) / 2);
  if (arr[middle] == i) {
    return true;
  } else if (i < arr[middle]) {
    return binarySearch(i, arr, left, middle - 1);
  } else {
    return binarySearch(i, arr, middle + 1, right);
  }
  return false;
}

vector<int> findDuplicates( const vector<int>& arr1, const vector<int>& arr2) 
{
  int M = arr1.size();
  int N = arr2.size();
  
  if (M == 0 || N == 0) return {};
  
  float ratio = 0.2;
  bool method = 0;
  if (N / M <= ratio) {
    method = 1;
  }
  
  // Scenario 1
  if (method == 0) {
    cout << "Chosen method 1" << endl;
    int i = 0;
    int j = 0;
    vector<int> result;
    while (i < M && j < N) {
      if (arr1[i] == arr2[j]) {
        result.push_back(arr1[i]);
        i++;
        j++;
      } else if (arr1[i] < arr2[j]) {
        i++;
      } else {
        j++;
      }
    }
    return result;
  } else { // Scenario 2
    cout << "Chosen method 2" << endl;
    vector<int> result;
    for (int i : arr2) {
      if (binarySearch(i, arr1, 0, M - 1)) {
        result.push_back(i);
      }
    }
    return result;
  }
}

int main() {
  vector<int> arr1, arr2, result;
  arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 , 19, 20, 21};
  arr2 = {3, 9, 22};
  
  result = findDuplicates(arr1, arr2);
  cout << result.size() << endl;
  for (auto c : result) cout << c << ",";
  return 0;
}
