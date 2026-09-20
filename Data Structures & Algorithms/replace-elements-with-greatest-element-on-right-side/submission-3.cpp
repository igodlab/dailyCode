class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int xi = arr[n - 1];
        vector<int> out(n);
        out[n - 1] = -1;
        for (int i = 1; i < n; ++i) {
            xi = max(xi, arr[n - i]);
            out[n - 1 - i] = xi;
        }
        return out;
    }
};