#include <iostream>
#include <vector>

using namespace std;

vector<long> arrayOfArrayProducts(const vector<int>& arr) 
{
  if (arr.size() <= 1) return {};
  vector<long> res(arr.size(), 1);
  // backward pass
  for (int i = arr.size() - 2; i >= 0; i--) {
    long prod = arr[i + 1] * res[i + 1];
    res[i] = prod;
  }
  // forward pass
  long prevProd = 1;
  for (int i = 1; i < arr.size(); i++) {
    long prod = arr[i - 1] * prevProd;
    res[i] = res[i] * prod;
    prevProd = prod;
  }
  return res;
}

int main() {
  vector<int> t1 = {8, 10, 2};
  vector<long> r1 = arrayOfArrayProducts(t1);
  for (auto& n : r1) cout << n << ", ";
  cout << endl;
  
  vector<int> t2 = {2, 7, 3, 4};
  vector<long> r2 = arrayOfArrayProducts(t2);
  for (auto& n : r2) cout << n << ", ";
  cout << endl;
  return 0;
}