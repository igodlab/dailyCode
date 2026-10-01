class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;
        for (int i = 0; i < nums.size(); ++i) {
            int delta = target - nums[i];
            auto ix = hm.find(delta);
            if (ix != hm.end()) {
                return {ix->second, i};
            }
            hm[nums[i]] = i;
        }
        return {};
    }
};
