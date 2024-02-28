class Solution {
public:
    void compare(string& str1, string& str2) {
        if (str1.length() > str2.length()) {
            str2 = str1;
        }
    }
    string longestPalindrome(string s) {
        string res = "", tmp = "";
        for (int i = 0; i < s.length(); i++) {
            int j = i, step = 0;
            while (j - step >= 0 && j + step < s.length()) {
                if (s[j - step] == s[j + step]) {
                    step += 1;
                } else {
                    tmp = s.substr(j - step + 1, 2 * step - 1);
                    compare(tmp, res);
                    break;
                }
            }
            if (j - step < 0) {
                tmp = s.substr(0, 2 * step - 1);
                compare(tmp, res);
            } else if (j + step >= s.length()) {
                tmp = s.substr(s.length() - 2 * step + 1);
                compare(tmp, res);
            }
        }
        for (int i = 0; i < s.length(); i++) {
            int j = i, step = 0;
            while (j - step - 1 >= 0 && j + step < s.length()) {
                if (s[j - step - 1] == s[j + step]) {
                    step += 1;
                } else {
                    tmp = s.substr(j - step, 2 * step);
                    compare(tmp, res);
                    break;
                }
            }
            if (j - step - 1 < 0) {
                tmp = s.substr(0, 2 * step);
                compare(tmp, res);
            } else if (j + step >= s.length()) {
                tmp = s.substr(s.length() - 2 * step);
                compare(tmp, res);
            }
        }
        return res;
    }
};

class Solution_2 {
public:
    string longestPalindrome(string s) {
        string res;
        int len = 0, num, tmp;
        for (int i = 0; i < s.length(); i++) {
            //回文串元素为奇数个
            num = 1;
            int j = i - 1;
            int k = i + 1;
            while (j >= 0 && k < s.length()) {
                if (s[j] == s[k]) {
                    num += 2;
                }
                else {
                    break;
                }
                j -= 1;
                k += 1;
            }
            if (num > len) {
                len = num;
                res = s.substr(j + 1, k - j - 1);
            }
            //回文串元素为偶数个
            tmp = 0;
            j = i - 1;
            k = i;
            while (j >= 0 && k < s.length()) {
                if (s[j] == s[k]) {
                    tmp += 2;
                }
                else {
                    break;
                }
                j -= 1;
                k += 1;
            }
            if (tmp > len) {
                len = tmp;
                res = s.substr(j + 1, k - j - 1);
            }
        }
        return res;
    }
};
