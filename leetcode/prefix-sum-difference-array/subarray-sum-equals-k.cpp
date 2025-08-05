// https://leetcode.com/problems/subarray-sum-equals-k/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        return my_prefix_sum(nums, k);
    }

    // My Soln
    // Time Complexity O(n)
    // Space Complexity O(n)
    int my_prefix_sum(const vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        freq_map[0] = 1;

        int n = nums.size();
        int running_sum = 0;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            running_sum += nums[i];
            ans += freq_map[running_sum - k];

            freq_map[running_sum]++;
        }

        return ans;
    }
};
