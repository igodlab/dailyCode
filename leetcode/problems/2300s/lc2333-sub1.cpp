#include <algorithm>
#include <iostream>
#include <vector>

#include <lc/print.hpp>

class Solution {
  public:
    long long minSumSquaredDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
      int n = nums1.size();
      std::vector<long> deltas(n);
      for (int i = 0; i < n; ++i) {
        long tmp = std::labs(nums1[i] - nums2[i]);
        deltas[i] = tmp;
      }
      std::sort(deltas.begin(), deltas.end());
      lc::printVector(deltas);
      int kk = k1 + k2;
      while (n - 1 > 0 && kk > 0) {
        if (deltas[n-1] >= deltas[n-2]) {
          --deltas[n-1];
          --kk;
        } else --n;
      }
      lc::printVector(deltas);
      return deltas[0];
    }
};

int main(void) {
  Solution sol;
  std::vector<int> v1{5, 2, -9, -1, 8, -8};
  std::vector<int> v2{-3, 7, 2, 11, -7, 0};
  int k1 = 4;
  int k2 = 2;
  long long minSum = sol.minSumSquaredDiff(v1, v2, k1, k2);
  std::cout << "minSum=" << minSum << "\n";
  return 0;
}
