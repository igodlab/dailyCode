class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const string& strs0 = strs[0];
        for (int i = 0; i < strs0.size(); ++i) {
            char c = strs0[i];
            for (auto itr = strs.begin() + 1; itr != strs.end(); ++itr) {
                if ((*itr)[i] != c || (*itr).size() == i) {
                    return strs0.substr(0, i);
                }
            }
        }
        return strs0;
    }
};