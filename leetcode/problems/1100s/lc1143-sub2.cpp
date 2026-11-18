#include <iostream>
#include <string>
#include <vector>

#include <lc/print.hpp>

class Solution {
  public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
      const size_t n = text1.size();
      const size_t m = text2.size();
      const size_t cols = m + 1;
      std::vector<int> mat((n+1) * cols, 0);
      for (size_t j = 0; j < n; ++j) {
        for (size_t i = 0; i < m; ++i) {
          if (text1[j] == text2[i]) mat[(j+1)*cols + i+1] = mat[j*cols + i] + 1;
          else mat[(j+1)*cols + i+1] = std::max(mat[(j+1)*cols + i], mat[j*cols + i+1]);
        }
      }
      return mat[n*cols + m];
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

