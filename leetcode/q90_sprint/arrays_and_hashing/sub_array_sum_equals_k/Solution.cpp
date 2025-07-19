class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // return brute_force(nums, k);
        // return brute_force_prefix(nums, k);
        return hashing(nums, k);
    }

    // Brute Force
    // Time Complexity O(n^2)
    // Space Complexity O(1)
    int brute_force(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int start = 0; start < n; ++start) {
            int cum_sum = 0;
            for (int end = start; end < n; ++end) {
                cum_sum += nums[end];
                if (cum_sum == k) count++;
            }
        }
        return count;
    }

    // Brute Force Prefix
    // Time Complexity O(n^2)
    // Space Complexity O(n)
    int brute_force_prefix(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> prefix_sum(n+1, 0);

        for (int i = 1; i < n + 1; ++i) {
            prefix_sum[i] =  prefix_sum[i-1] + nums[i-1];
        }

        for (int start = 0; start < n; ++start) {
            for (int end = start; end < n; ++end) {
                int sum = prefix_sum[end + 1] - prefix_sum[start];
                if (sum == k) count++;
            }
        }
        return count;
    }

    // HashMap
    // Time Complexity O(n)
    // Space Complexity O(n)
    int hashing(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefix_sum_freq;
        prefix_sum_freq[0] = 1;

        int sum_cum = 0;
        int count = 0;
        for (int index = 0; index < n; ++index) {
            sum_cum += nums[index];
            if (prefix_sum_freq.count(sum_cum - k)) {
                count += prefix_sum_freq[sum_cum - k];
            }
            prefix_sum_freq[sum_cum]++;
        }
        return count;
    }
}