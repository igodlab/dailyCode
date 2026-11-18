#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include <lc/print.hpp>

class Solution {
  public:
    int firstStableIndedx(std::vector<int>& nums, int k) {
      size_t n = nums.size();
      std::vector<int> left_chunk(n), right_chunk(n);

      left_chunk[0] = nums[0];
      right_chunk[n-1] = nums[n-1];
      for (size_t i = 1; i < n; ++i) {
        left_chunk[i] = std::max(nums[i], left_chunk[i-1]);
        right_chunk[n-1-i] = std::max(nums[n-1-i], right_chunk[n-i]);
      }

      for (int i = 0; i < n; ++i) {
        if (left_chunk[i] - right_chunk[i] <= k) return i;
      }
      return -1;
    }
};


int main(void) {
  Solution sol;
  //                    0,                                   10, 11
  std::vector<int> v1 {83, 54, 3, 4, 65, 15, 24, 11, 17, 32, 20, 35};
  int v10 = sol.firstStableIndedx(v1, 27);
  std::cout << "index=" << v10 << "\n";
  return 0;
}
