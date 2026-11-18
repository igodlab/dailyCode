#include <algorithm>
#include <vector>

#include <lc/print.hpp>

class Solution {
  public:
    std::vector<int> findEvenNumbers(std::vector<int>& digits) {
      cleanOdd(digits);
      return digits;
    }

    std::vector<int> cleanOdd(std::vector<int>& x) {
      std::vector<int> hist(10);
      std::vector<int> vec;
      for (auto xi : x) {
        hist[xi] += 1;
      }
      for (size_t i = 0; i < hist.size(); ++i) {
        if (i % 2 != 0) continue;
        if (i == 0) {
          vec.push_back(i);
          continue;
        }
        for (; hist[i] > 0; --hist[i]) {
          vec.push_back(i);
        }
      }
      return vec;
    }
};


int main(void) {
  Solution sol;
  std::vector v1 {0, 1, 7, 0, 9, 5, 7, 8, 6, 2, 1, 1, 0, 8, 9, 6, 2, 2, 4};
  lc::printVector(v1);
  std::vector<int> v2 = sol.cleanOdd(v1);
  lc::printVector(v2);
  return 0;
}
