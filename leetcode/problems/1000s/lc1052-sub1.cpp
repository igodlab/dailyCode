#include <vector>
#include <iostream>

#include <lc/print.hpp>

class Solution {
  public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
      int acc = 0;
      int best = 0;
      size_t lo = 0;
      size_t n = customers.size();
      for (size_t hi = 0; hi < n; ++hi) {
        std::cout << "(lo, hi) = (" << lo << ", " << hi << ")\n";
        if (hi - lo + 1 > minutes) { 
          acc -= grumpy[lo] * customers[lo];
          ++lo;
        }
        acc += customers[hi];
        if (!grumpy[hi]) best += customers[hi];
        best = std::max(best, acc);
      }
      return best;
    }
};

int main(void) {
  Solution sol;
  std::vector<int> c1 {1,0,1,2,1,1,7,5,2,1,1,4,11,12,4};
  std::vector<int> g1 {0,1,0,1,0,1,0,1,0,0,1,0,0,0,0};
  int min1 = 3;
  std::cout << "satisfied customers: " << sol.maxSatisfied(c1, g1, min1) << "\n";
  return 0;
}
