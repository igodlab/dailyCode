class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            int max_to_right = 0;
            for (int j = i + 1; j < arr.size(); ++j) {
                if (max_to_right < arr[j]) {
                    max_to_right = arr[j];
                }
            }
            arr[i] = max_to_right;
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};