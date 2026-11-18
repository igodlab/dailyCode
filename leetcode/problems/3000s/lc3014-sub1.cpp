#include <algorithm>
#include <iostream>
#include <vector>

#include <lc/print.hpp>


class Solution {
  public:
    int minimumPushes(std::string word) {
      std::vector<int> hist(26);
      for (auto& c: word) ++hist[c - 'a'];
      std::ranges::sort(hist, std::greater());

      int buttons = 8; // from keys 2 to 9
      int pushes = 0;
      for (size_t i = 0; i < 26; ++i) {
        pushes += hist[i] * (1 + (i / buttons));
        hist[i] = 0;
      }
      return pushes;
    }
};

int main(void) {
  Solution sol;
  std::string w1 = "xycdefghij";
  std::string w2 = "abcde";
  int pushes1 = sol.minimumPushes(w1);
  int pushes2 = sol.minimumPushes(w2);
  std::cout << "pushes to write '" << w1 << "' on custom keypad is: " << pushes1 << "\n";
  std::cout << "pushes to write '" << w2 << "' on custom keypad is: " << pushes2 << "\n";
  return 0;
}
