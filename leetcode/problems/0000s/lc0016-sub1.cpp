#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include <lc/print.hpp>

using namespace std;

class Solution {
  public:
    vector<int> allCombinations(vector<int>& nums) {
      const int n = nums.size();
      vector<int> y;
      if (n < 3) return {0};
      else y.reserve(n*(n-1)*(n-2)/6);
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          for (int k = j + 1; k < n; ++k) {
            y.push_back(nums[i] + nums[j] + nums[k]);
          }
        }
      }
      return y;
    }

    int threeSumClosest(vector<int>& nums, int target) {
      // Brute force it
      // Sort $\vec{x}$ and create $\vec{z} = [ \sum_{i,j,k}^{n-1} x_i+x_j+x_k ]$
      // where $\vec{x} \in \mathbb{N}^{n}$ and $\vec{z} \in \mathbb{N}^{n^3}$
      int n = nums.size();
      unordered_map<int, int> z;
      z.reserve((n-2)*(n-1)*n/6);
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          for (int k = j + 1; k < n; ++k) {
            int sum_three = nums[i] + nums[j] + nums[k];
            cout << "(i=" << i << ", j=" << j << ", k=" << k << ") : nums(" << nums[i] << ", " << nums[j] << ", " << nums[k] << ") = " << sum_three << "\n";
            z.insert({sum_three, abs(sum_three - target)});
          }
        }
      }
      if (z.empty()) return 0;
      auto min_key = min_element(
          z.begin(),
          z.end(),
          [](const auto& a, const auto& b) {
            return a.second < b.second; 
          }
      );
      return min_key->first;
    }
};


int main(void) {
  Solution sol;
  vector<int> x1 {21, -35, 1, 0, -7, 6, 9, 16, -22, 100, -374};
  vector<int> x2 {1, 2, -1, 0, 4}; //, -2, 5};
  lc::printVector(x2);
  vector<int> guac = sol.allCombinations(x2);
  lc::printVector(guac);
  return 0;
}
