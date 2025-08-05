// https://leetcode.com/problems/split-array-largest-sum/description/

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // return binary_search_greedy(nums, k);
        // return top_down_dp_manager(nums, k);
        return bottom_up_dp_manager(nums, k);

    }

    // Binary Search the solution
    // Time Complexity O(logS * N), S -> sum of elements of array
    // Space Complexity O(1) 
    int binary_search_greedy(const vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for (int num: nums) {
            high += num;
        }

        // FFFFFFTTTTTTT
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (!is_solution(mid, nums, k)) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }

    bool is_solution(int upper_limit_per_subarray, const vector<int>& nums, int k) {
        int num_subarrays = 1;
        int run_sum = 0;
        for (int num: nums) {
            run_sum += num;
            if (run_sum > upper_limit_per_subarray) {
                num_subarrays++;
                run_sum = num;
            }
        }
        return num_subarrays <= k;
    }


    // Top Down DP
    // Time Complexity O(N^2 * K)
    // Space Complexity O(N * K)
    int top_down_dp_manager(const vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k + 1, -1));
        return top_down_dp(0, nums, k, dp);
    }

    int top_down_dp(int index, const vector<int>& nums, int k, vector<vector<int>>& dp) {
        if (dp[index][k] != -1) return dp[index][k];

        if (k == 1) {
            int sum = 0;
            for (int i = index; i < nums.size(); ++i) {
                sum += nums[i];
            }
            dp[index][k] = sum;
            return dp[index][k];
        }

        int run_sum = 0;
        int ans = INT_MAX;
        for (int i = index; i <= nums.size() - k; ++i) {
            run_sum += nums[i];
            ans = min(
                ans,
                max(
                    run_sum,
                    top_down_dp(i + 1, nums, k - 1, dp)
                )
            );
        }
        dp[index][k] = ans;
        return dp[index][k];
    }

    // Bottom Up Dp
    // Time Complexity O(N^2 * K)
    // Space Complexity O(N * K)
    int bottom_up_dp_manager(const vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k + 1));
        vector<int> prefix_sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }


        for (int k_left = 1; k_left <= k; ++k_left) {

            for (int i = 0; i < nums.size(); ++i) {
                if (k_left == 1) {
                    dp[i][k_left] = prefix_sum[nums.size()] - prefix_sum[i];
                }
                else {
                    int min_run = INT_MAX;
                    for (int j = i; j <= nums.size() - k_left; ++j) {
                        min_run = min(
                            min_run,
                            max(
                                prefix_sum[j + 1] - prefix_sum[i],
                                dp[j + 1][k_left - 1]
                            )
                        );
                    }
                    dp[i][k_left] = min_run;
                }
            }
        }
        return dp[0][k];
    }
};
