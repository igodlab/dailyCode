#include <algorithm>
#include <string>
#include <lc/print.hpp>

class Solution {
  public:
    std::string smallestPalindrome(std::string& s) {
      return s;
    }
};

int main(void) {
  Solution sol;
  std::string s1 = "cbbacbcabbc";
  lc::printVector(s1);
  std::nth_element(s1.begin(), s1.begin()+11, s1.end());
  lc::printVector(s1);
  return 0;
}
