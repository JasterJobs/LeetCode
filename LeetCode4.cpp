class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        bool flag = (sz1 + sz2) % 2;
        int start = (sz1 + sz2) / 2;
        double res = 0, tmp = 0;
        int i = 0, j = 0, count = 0;
        while (i < sz1 || j < sz2) {
            if ((i < sz1 && j < sz2)) {
                if (nums1[i] < nums2[j]) {
                    tmp = nums1[i];
                    i++;
                } else {
                    tmp = nums2[j];
                    j++;
                }
            } else if (i < sz1) {
                tmp = nums1[i];
                i++;
            } else {
                tmp = nums2[j];
                j++;
            }
            count += 1;
            if (flag == 1) {
                if (count == start + 1) {
                    return tmp;
                }
            } else {
                if (count == start || count == start + 1) {
                    res += tmp;
                }
            }
        }
        return res / 2.0;
    }
};
