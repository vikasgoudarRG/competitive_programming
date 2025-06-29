// https://leetcode.com/problems/find-right-interval/submissions/1654599899/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> end_index_pair(intervals.size());
        for (int i = 0; i < intervals.size(); ++i) {
            end_index_pair[i] = {intervals[i][0], i};
        }
        sort(end_index_pair.begin(), end_index_pair.end());

        vector<int> ans(intervals.size());

        for (int i = 0; i < ans.size(); ++i) {
            int left = 0;
            int right = end_index_pair.size();
            int target = intervals[i][1];
            while (left < right) {
                int middle = left + (right - left) / 2;
                if (end_index_pair[middle].first >= target) {
                    right = middle;
                }
                else {
                    left = middle + 1;
                }
            }
            ans[i] = left == end_index_pair.size() ? -1 : end_index_pair[left].second;
        }

        return ans;
    }
};
