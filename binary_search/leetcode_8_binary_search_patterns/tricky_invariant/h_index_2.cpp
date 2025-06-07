// https://leetcode.com/problems/h-index-ii/submissions/1657001966/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0;
        int r = n;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (citations[m] >= n - m) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return n - l;
    }
};
