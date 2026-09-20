class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int xi = -1;
        vector<int> out(n);
        for (int i = 0; i < n; ++i) {
            out[n - 1 - i] = xi;
            xi = max(xi, arr[n -1 - i]);
        }
        return out;
    }
};