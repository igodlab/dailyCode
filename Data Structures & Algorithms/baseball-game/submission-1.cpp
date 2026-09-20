class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> vals;
        for (int i = 0; i < operations.size(); ++i) {
            if (operations[i] == "+") {
                int sum = vals[vals.size()-2] + vals[vals.size()-1];
                vals.push_back(sum);
            } else if (operations[i] == "D"){
                vals.push_back(2*vals[vals.size() - 1]);
            } else if (operations[i] == "C") {
                vals.pop_back();
            } else vals.push_back(stoi(operations[i]));
        }
        int tot = 0;
        for (int vi: vals) {
            tot += vi;
        }
        return tot;
    }
};