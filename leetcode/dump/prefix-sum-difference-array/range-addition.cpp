// https://leetcode.com/problems/range-addition/description/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        return my_prefix_soln(length, updates);
    }

    // My Soln
    // Prefix soln
    // Time Complexity O(n)
    // Space Complexity O(1)
    vector<int> my_prefix_soln(int length, const vector<vector<int>>& updates) {
        vector<int> ans(length, 0);

        for (vector<int> v: updates) {
            int start = v[0];
            int end = v[1];
            int update = v[2];

            ans[start] += update;
            if (end + 1 < length) ans[end + 1]   -= update;
        }

        int run_sum = 0;
        for (int i = 0; i < length; ++i) {
            run_sum += ans[i];
            ans[i] = run_sum;
        }

        return ans;
    }
};
