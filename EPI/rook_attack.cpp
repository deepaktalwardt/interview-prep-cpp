#include <vector>
#include "test_framework/generic_test.h"
#include <climits>
using std::vector;

void RookAttack(vector<vector<int>>* A_ptr) {
  // TODO - you fill in here.
  int rows = A_ptr->size();
  int cols = (A_ptr->at(0)).size();
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          if ((A_ptr->at(i))[j] == 0) {
              for (int k = 0; k < cols; k++) {
                  if ((A_ptr->at(i))[k] != 0) {
                      A_ptr->at(i)[k] = INT_MIN;
                  }
              }
              for (int k = 0; k < rows; k++) {
                  if ((A_ptr->at(k))[j] != 0) {
                      A_ptr->at(k)[j] = INT_MIN;
                  }
              }
          }
      }
  }
  for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
          if ((A_ptr->at(i))[j] == INT_MIN) {
              (A_ptr->at(i))[j] = 0;
          }
      }
  }
  return;
}
vector<vector<int>> RookAttackWrapper(vector<vector<int>> A) {
  vector<vector<int>> a_copy = A;
  RookAttack(&a_copy);
  return a_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "rook_attack.cc", "rook_attack.tsv",
                         &RookAttackWrapper, DefaultComparator{}, param_names);
}
