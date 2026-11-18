#include <algorithm>
#include <iostream>
#include <vector>

#include <lc/print.hpp>

class Solution {
  public:
    long long sellingWood(int m, int n, std::vector<std::vector<int>>& prices) {
      long long wii = 100;
      return wii;
    }

    std::vector<std::vector<int>> sortedPrices(std::vector<std::vector<int>>& prices) {
      std::ranges::sort(prices, 
          [](std::vector<int>& a, std::vector<int>& b){
            return a.back() > b.back();
          });
      return prices;
    }
};

int main(void) {
  Solution sol;
  std::vector<int> v1 {2, 5, 4};
  std::vector<int> v2 {4, 3, 7};
  std::vector<int> v3 {3, 1, 2};
  std::vector<std::vector<int>> prz {v1, v2, v3};
  std::cout << "mat:\n";
  for (auto xi: prz) lc::printVector(xi);
  std::cout << "mat:\n";
  for (auto xi: sol.sortedPrices(prz)) lc::printVector(xi);
  return 0;
}
