class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int i = 0, sign = 1;
        while (s[i] == ' ' && i < s.length()) {
            i++;
        }
        if (s[i] == '+' || s[i] == '-') {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }
        while (i < s.length() && isdigit(s[i])) {
            res = res * 10 + s[i] - '0';
            if (res > INT_MAX) {
                return res = sign == 1 ? INT_MAX : INT_MIN;
            }
            i++;
        }
        return sign * res;
    }
};
