class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j = 0; 
        int acc = 0;
        for (int xi: nums) {
            if (xi == 0) {
                j = max(j, acc);
                acc = 0;
            } else {
                ++acc;
            }
        }
        return max(j, acc);
    }
};