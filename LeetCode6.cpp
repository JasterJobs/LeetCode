class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res = "";
        for (int j = 1; j <= numRows; j++) {
            if (j == 1 || j == numRows) {
                int step = 2 * numRows - 2;
                for (int k = j - 1; k < s.length(); k += step) {
                    res += s[k];
                }
            } else {
                bool flag = 1;
                int step1 = 2 * numRows - 2 * j;
                int step2 = 2 * j - 2;
                for (int k = j - 1; k < s.length();) {
                    res += s[k];
                    k += flag ? step1 : step2;
                    flag = !flag;               
                }
            }
        }
        return res;
    }
};
