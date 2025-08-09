// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        // return prefix_solution(nums, k);
        // return sliding_window(nums, k);
        // return sliding_window_optimized(nums, k);
        return at_most_sliding_window_manager(nums, k);
    }

    // Prefix Solution 
    // Time Complexity O(n)
    // Space Complexity O(k)
    int prefix_solution(std::vector<int>& nums, int k) {
        int run_odd_count = 0;
        std::unordered_map<int, int> odd_count_freq;
        odd_count_freq[0] = 1;
        int num_nice_subarrays = 0;
        for (int elem: nums) {
            if (elem & 1) run_odd_count++;
            num_nice_subarrays += odd_count_freq[run_odd_count - k];
            odd_count_freq[run_odd_count]++;
        }

        return num_nice_subarrays;
    }

    // Sliding Window 
    // Time Complexity O(n)
    // Space Complexity O(k)
    int sliding_window(const std::vector<int>& nums, int k) {
        int nums_len = nums.size();
        int low = 0;
        int high = 0;

        int last_one = -1;
        std::queue<int> que;

        int num_nice_subarray = 0;

        while (high < nums_len) {
            int nums_high = nums[high];
            if (nums_high & 1) {
                que.push(high);
            }

            while (que.size() > k) {
                last_one = que.front();
                que.pop();
            }

            if (que.size() == k) {
                num_nice_subarray += que.front() - last_one;
            }

            high++;
        }

        return num_nice_subarray;
    }

    // Sliding Window Optimized 
    // Time Complexity O(n)
    // Space Complexity O(1)
    int sliding_window_optimized(const std::vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int nums_len = nums.size();

        int run_one_count = 0; // NOTE: Variable label misleading what i mean was Odd not One, but I dont want to fix this code now
        int initial_gap = 0;
        int num_nice_subarrays = 0;
        while (high < nums_len) {
            int num_high = nums[high];
            if (num_high & 1) run_one_count++;

            if (run_one_count == k) {
                initial_gap = 0;
                while (run_one_count == k) {
                    initial_gap++;
                    if (nums[low] & 1) run_one_count--;
                    low++;
                }
            }
            num_nice_subarrays += initial_gap;
            high++;
        }
        return num_nice_subarrays;
    }

    // At Most Sliding Window
    // Time Complexity 
    // Space Complexity 
    int at_most_sliding_window_manager(const std::vector<int>& nums, int k) {
        return at_most_sliding_window(nums, k) - at_most_sliding_window(nums, k - 1);
    }

    int at_most_sliding_window(const std::vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int nums_len = nums.size();
        int run_odd_count = 0;
        int num_substring = 0;

        while (high < nums_len) {
            int num_high = nums[high];
            if (num_high & 1) run_odd_count++;

            while (run_odd_count > k) {
                int num_low = nums[low];
                if (num_low & 1) run_odd_count--;
                low++;
            }
            num_substring += high - low + 1;
            high++;
        }
        return num_substring;
    }        
};
