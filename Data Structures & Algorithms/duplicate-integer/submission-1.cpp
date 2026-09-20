class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> valIx;
        for (int i = 0; i < nums.size(); ++i) {
            if (valIx.find(nums[i]) != valIx.end()) {
                return true;
            }
            valIx[nums[i]] = i;
        }
        return false;
    }
};