// 遍历字符串,遇到重复字符,刷新map
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, len = 0;
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) == map.end()) {
                map.insert(make_pair(s[i], i));
                len += 1;
                if (len > res) {
                    res = len;
                }
            } else {
                int index = map[s[i]];
                len = i - index;
                map.clear();
                for (int j = index + 1; j <= i; j++) {
                    map.insert(make_pair(s[j], j));
                }
            }
        }
        return res;
    }
};

//始终维护s[i,...,j]是一个无重复的字串
class Solution_2 {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, j = 0;
        unordered_set<char> set;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0) {
                set.erase(s[i - 1]);
            }
            while (j < s.length()) {
                if (set.find(s[j]) == set.end()) {
                    set.insert(s[j]);
                    j++;
                } else {
                    break;
                }
            }
            if (j - i > res) {
                res = j - i;
            }
        }
        return res;
    }
};
