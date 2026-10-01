class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid+1, hi);
        merge_(nums, lo, mid, hi);
    }

    void merge_(vector<int>& nums, int lo, int mid, int hi) {
        vector<int> tmp(hi-lo+1);
        for (int i = 0; i < tmp.size(); ++i) tmp[i] = nums[i+lo];

        int i = lo;
        int j = mid+1;
        int k = lo;

        while (i <= mid && j <= hi) {
            if (tmp[i-lo] <= tmp[j-lo]) {
                nums[k] = tmp[i-lo];
                ++i;
            } else {
                nums[k] = tmp[j-lo];
                ++j;
            }
            ++k;
        }
        while (i <= mid) {
            nums[k] = tmp[i-lo];
            ++i;
            ++k;
        }
        while (j <= hi) {
            nums[k] = tmp[j-lo];
            ++j;
            ++k;
        }
    }
};