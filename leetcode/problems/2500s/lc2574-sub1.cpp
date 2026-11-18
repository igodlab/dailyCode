#include <iostream>
#include <vector>

#include <lc/print.hpp>


class Solution {
  public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
      int n = nums.size();
      std::vector<int> acc(2*n);
      std::vector<int> answer(n);
      acc[0] = 0;
      acc[2*n-1] = 0;
      for (int i = 1; i < n; ++i) {
        acc[i] += acc[i-1] + nums[i-1];
        acc[2*n-1-i] += acc[2*n-i] + nums[n-i];
      }
      for (int i = 0; i < n; ++i) answer[i] = abs(acc[i] - acc[n+i]);
      return answer;
    }
};

int main(void) {
  Solution sol;
  std::vector<int> v1 {10, 4, 8, 3};
  lc::printVector(v1);
  std::vector<int> v2 = sol.leftRightDifference(v1);
  lc::printVector(v2);
  return 0;
}
