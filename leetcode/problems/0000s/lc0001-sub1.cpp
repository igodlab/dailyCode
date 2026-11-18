// 1. Two Sum — https://leetcode.com/problems/two-sum/
#include <lc/prelude.hpp>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;   // value -> index
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (auto it = seen.find(target - nums[i]); it != seen.end())
                return {it->second, i};
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> a{2, 7, 11, 15};
    vector<int> b{3, 2, 4};
    lc::print(Solution{}.twoSum(a, 9));   // [0, 1]
    lc::print(Solution{}.twoSum(b, 6));   // [1, 2]
}
