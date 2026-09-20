class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int largest_acc = 0; 
        int acc = 0;
        for (int xi: nums) {
            if (xi == 1) {
                ++acc;
                if (acc > largest_acc) {
                    largest_acc = acc;
                }
            } else {
                acc = 0;
            }
        }
        return largest_acc;
    }
};