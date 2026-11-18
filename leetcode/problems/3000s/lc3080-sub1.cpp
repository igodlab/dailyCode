#include <algorithm>
#include <ranges>
#include <vector>
#include <lc/print.hpp>

class Solution {
  public:
    std::vector<long long> unmarkedSumArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
      std::vector<bool> marked(nums.size(), false);
      std::vector<long long> ans;
      ans.reserve(queries.size());
      long long acc_sum = 0;
      for (auto& xi: nums) acc_sum += static_cast<long long>(xi);

      auto ix = std::views::iota(size_t{0}, nums.size()) | std::ranges::to<std::vector>();
      std::ranges::sort(ix, {}, 
          [&](int xi) {
          return std::pair{nums[xi], xi};
          });

      long long subs = 0;
      size_t track_tail = 0;
      for (auto& q: queries) {
        if (!marked[q[0]]) {
          subs += nums[q[0]];
          marked[q[0]] = true;
        }
        size_t j = 0;
        while (j < q[1] && track_tail < ix.size()) {
          if (!marked[ix[track_tail]]) {
            subs += nums[ix[track_tail]];
            marked[ix[track_tail]] = true;
            ++track_tail;
            ++j;
          } else ++track_tail;
        }
        ans.push_back(acc_sum - subs);
      }
      return ans;
    }
};

int main(void) {
  Solution sol;
  std::vector<int> v1 {1,2,2,1,2,3,1};
  std::vector<std::vector<int>> q1 {{1,2}, {3,3}, {4,2}};
  lc::printVector(sol.unmarkedSumArray(v1, q1)); // ans: [8,3,0]
  return 0;
}
