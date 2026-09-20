class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 != 0) return false;
        stack<char> cnt;
        for (char si: s) {
            if ('(' == si || '{' == si || '[' == si) {
                cnt.push(si);
            } else if (')' == si || '}' == si || ']' == si) {
                if (cnt.empty() || invertPar(cnt.top()) != si) {
                    return false;
                } else cnt.pop();
            }
        }
        return cnt.empty();
    }

    char invertPar(char c) {
        switch (c) {
            case '(':
                return ')';
            case '{':
                return '}';
            case '[':
                return ']';
            default: 
                return '#';
        }
    }
};
