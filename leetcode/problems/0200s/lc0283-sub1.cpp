#include <iostream>
#include <vector>

#include <lc/print.hpp>

using namespace std;

class Solution {
  public:
    void moveZeroes(vector<int>& x) {
      int l = 0;
      int tmp;
      for (int r = 0; r < x.size(); ++r) {
        cout << "x[" << r <<  "]=" << x[r];
        cout << " & x[" << l <<  "]=" << x[l] << "\n";
        if (x[r] != 0) {
          tmp = x[r];
          x[r] = x[l];
          x[l] = tmp;
          ++l;
        }
      }
    }
};

int main(void) {
  Solution sol;
  vector<int> v {0, 1, 2, 0, 5, 0};
  lc::printVector(v);
  sol.moveZeroes(v);
  lc::printVector(v);
  return 0;
}

