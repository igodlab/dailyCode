#include <iostream>
#include <unordered_map>
#include <vector>

#include <lc/print.hpp>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &x) {
      int n = x.size();
      if (x.empty() || n < 3) return {x};
      vector<vector<int>> z;
      for (int i = 0; i < n; ++i) {
        int j = i + 1;
        unordered_map<int, int> hm {};
        hm[i] = x[i];
        while (j != i && j < n) {
          int complement = x[i] + x[j];
          auto ix = hm.find(-complement);
          if (ix != hm.end()) {
            z.push_back({x[i], x[j], ix->second});
          }
          hm[j] = x[j];
          ++j;
        }
      }
      return z;
    }
};

int main(void) {
  Solution sol;
  vector<int> v1 {-1,0,1,2,-1,-4};
  lc::printVector(v1);
  vector<vector<int>> vv = sol.threeSum(v1);
  lc::printVector(vv[0]);
  return 0;
}
