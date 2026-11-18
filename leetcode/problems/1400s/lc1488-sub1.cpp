#include <ranges>
#include <set>
#include <unordered_map>
#include <vector>

#include <lc/print.hpp>

class Solution {
  public:
    std::vector<int> avoidFloods(std::vector<int>& rains) {
      std::vector<int> ans(rains.size(),1);
      std::unordered_map<int, int> mp;
      std::set<int>  dry_budget;

      for (auto [i, ith_lake]: std::views::enumerate(rains)) {
        if (ith_lake == 0) {
          dry_budget.insert(i);
          continue;
        }
        auto ix = mp.find(ith_lake);
        if (ix != end(mp)) {
          auto fst_dry_day = dry_budget.upper_bound(ix->second);
          if (fst_dry_day == end(dry_budget)) return {};
          ans[*fst_dry_day] = ith_lake;
          dry_budget.erase(fst_dry_day);
        }
        mp[ith_lake] = i;
        ans[i] = -1;
      }
      return ans;
    }
};

int main(void) {
  Solution sol;
  std::vector<int> v1 {1,2,3,4};     // [-1,-1,-1,-1]
  std::vector<int> v2 {1,2,0,0,2,1}; // [-1,-1,2,1,-1,-1]
  std::vector<int> v3 {1,2,0,1,2};   // []
  std::vector<int> v4 {1,0,2,0,2,1}; // [-1,1,-1,2,-1,-1]
  std::vector<int> v5 {0,1,1};       // []

  lc::printVector(sol.avoidFloods(v1));
  lc::printVector(sol.avoidFloods(v2));
  lc::printVector(sol.avoidFloods(v3));
  lc::printVector(sol.avoidFloods(v4));
  lc::printVector(sol.avoidFloods(v5));
  return 0;
}
