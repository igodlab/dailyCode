#include <algorithm>
#include <iostream>
#include <vector>
#include <lc/print.hpp>

using namespace std;

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      sort(begin(points), 
          end(points), 
          [](const auto& x, const auto& y) {
          return x[0]*x[0] + x[1]*x[1] < y[0]*y[0] + y[1]*y[1];
          }
      );
      return vector<vector<int>>(begin(points), begin(points)+k);
    }
};


int main(void) {
  Solution sol;
  vector<vector<int>> v1 {{4,3},{5,-2},{-2,8}, {-2, 3}, {1, -10}, {9, 2}, {3, -2}};
  vector<vector<int>> v1_closest = sol.kClosest(v1, 4);
  for (auto i: v1_closest) {
    lc::printVector(i);
  }
  vector<int> v2 {3,-4,7,9,-4, -5};
  vector<int> v3 {-1,9,2,1,-8, 5};
  vector<int> v4 = v2 - v3;
  cout << "x - y" << v4 << "\n";
  return 0;
}

