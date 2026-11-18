#include <iostream>
#include <ranges>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include <lc/print.hpp>

class Solution {
public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
        std::unordered_map<char, std::set<size_t>> mp1; // char, [indexes where it appears]
        std::unordered_map<char, std::set<size_t>> mp2; 
        for (auto [i, c1]: std::views::enumerate(text1)) mp1[c1 - 'a'].insert(i);
        for (auto [i, c2]: std::views::enumerate(text2)) mp2[c2 - 'a'].insert(i);

        std::vector<int> common_chars;
        for (size_t ch = 0; ch < 26; ++ch) {
            if (mp1[ch].empty() || mp2[ch].empty()) {
                continue;
            } else common_chars.push_back(ch);
        }

        std::set<size_t> s1;
        for (auto& c: common_chars) {
            s1.insert(mp1[c].begin(), mp1[c].end());
        }

        std::vector<size_t> tails;
        for (size_t i: s1) {
          const auto& positions = mp2[text1[i] - 'a'];

          // walk text2 positions in descending order
          for (auto it = positions.rbegin(); it != positions.rend(); ++it) {
            size_t j = *it;
            auto pos = std::lower_bound(tails.begin(), tails.end(), j);
            if (pos == tails.end()) tails.push_back(j);
            else *pos = j;
          }
        }

        return static_cast<int>(tails.size());
    }
};

int main(void) {
  Solution sol;
  std::string s1 = "oxcpqrsvwf";
  std::string s2 = "shmtulqrypy";
  int sz = sol.longestCommonSubsequence(s1, s2);
  std::cout << "logest common subsequence = " << sz << "\n";
  std::string s3 = "leetcode";
  std::string s4 = "etco";
  int sz2 = sol.longestCommonSubsequence(s3, s4);
  std::cout << "logest common subsequence = " << sz2 << "\n";
  return 0;
}
