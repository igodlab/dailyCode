#include <vector>

#include <lc/print.hpp>

class Solution {
  public: 
    std::vector<int> totalNumbers(std::vector<int>& digits) {
      std::vector<int> ans;
      std::vector<int> hist(10);
      for (auto& di: digits) ++hist[di];

      for (size_t i = 1; i <= 9; ++i) {
        if (hist[i] == 0) continue;
        --hist[i];
          for (size_t j = 1; j <= 9; ++j) {
            if (hist[j] == 0) continue;
            --hist[j];
          }
      }
    }
};
