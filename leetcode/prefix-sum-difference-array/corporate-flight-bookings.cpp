// https://leetcode.com/problems/corporate-flight-bookings/description/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        return my_difference_array(bookings, n);
    }

    // My Soln
    // Difference Array 
    // Time Complexity O(n)
    // Space Complexity O(1)
    vector<int> my_difference_array(const vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);

        for (vector<int> v: bookings) {
            int start = v[0] - 1;
            int end   = v[1] - 1;
            int book  = v[2];

            ans[start] += book;
            if (end + 1 < n) ans[end + 1] -= book; 
        }

        int run_sum = 0;
        for (int i = 0; i < ans.size(); ++i) {
            run_sum += ans[i];
            ans[i] = run_sum;
        }

        return ans;
    }
};
