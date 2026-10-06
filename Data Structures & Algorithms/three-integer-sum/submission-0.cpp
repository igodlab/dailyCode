class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> z {};
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum_three = nums[i] + nums[l] + nums[r];
                if (sum_three < 0) ++l;
                else if (sum_three > 0) --r;
                else {
                    z.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l-1]) ++l;
                    while (l < r && nums[r] == nums[r+1]) --r;
                }

            }
        }
        return z;
    }
};
