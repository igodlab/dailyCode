#include <iostream>
#include <bitset>
#include <vector>

#include <lc/print.hpp>

using namespace std;

class Solution {
  public:
    bool validUtf8(vector<int>& data) {
      unsigned char nbytes = 1U;
      cout << "nbytes=" << nbytes << "\n";
      for (auto itr = data.begin(); itr != data.end(); ++itr) {
        if (nbytes == 1) nbytes = nByteSequence(*itr);
        else if (nbytes == 0) return false;
        else if (*itr >> (w - 2) != 0b00000010) return false;
        else --nbytes;
        cout << "nbytes=" << nbytes << "\n";
      }
      return true;
    }
  private:
    unsigned char w = sizeof(unsigned char) << 3;
    int nByteSequence(unsigned char x) {
      unsigned char nbytes;
      if (x >>  (w - 1) == 0b00000000) nbytes = 1;
      else if (x >> (w - 3) == 0b00000110) nbytes = 2;
      else if (x >> (w - 4) == 0b00001110) nbytes = 3;
      else if (x >> (w - 5) == 0b00011110) nbytes = 4;
      else nbytes = 0;

      return nbytes;
    }
};

int main(void) {
  Solution sol;
  vector<int> v {197, 130, 1};
  bool sv = sol.validUtf8(v);
  // cout << sv << "\n";
  cout << "1 << 0 = " << bitset<32>(v[0]) << "\n"; 
  cout << "1 << 0 = " << bitset<32>(v[1]) << "\n"; 
  cout << "1 << 0 = " << bitset<32>(v[2]) << "\n"; 
  // cout << "0xFF >> 8 = " << bitset<8>(0xFF >> (8 - 2)) << "\n"; 
  return 0;
}
