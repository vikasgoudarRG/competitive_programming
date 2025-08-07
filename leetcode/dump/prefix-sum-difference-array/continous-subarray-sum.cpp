// https://leetcode.com/problems/continuous-subarray-sum/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        return my_prefix_soln(nums, k);
    }

    // My Soln 
    // Prefix array with remainder 
    // Time Complexity O(n)
    // Space Complexity O(1)
    bool my_prefix_soln(const vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> seen;

        int run_sum = 0;
        seen[0] = -1;

        for (int i = 0; i < n; ++i) {
            run_sum = (run_sum + nums[i]) % k;

            if (seen.count(run_sum)) {
                if (i - seen[run_sum] > 1) return true;
            }
            else {
                seen[run_sum] = i;
            }
        }

        return false;
    }
};
