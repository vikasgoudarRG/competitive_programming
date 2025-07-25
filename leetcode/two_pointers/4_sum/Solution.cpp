class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return k_sum(nums, 0, target, 4);
    }

    // K - Pointer
    // Time Complexity O(n ^ k)
    // Space Complexity O(k)
    vector<vector<int>> k_sum(vector<int>& nums, int start, long long target, int k) {
        int n = nums.size();

        if (start == n) {
            return {};
        }
        long long avg_needed = target / k;
        if (nums[start] > avg_needed || nums[n-1] < avg_needed) {
            return {};
        }

        if (k == 2) {
            return two_pointer(nums, start, target);
        }

        vector<vector<int>> ans;
        
        for (int i = start; i < n; ++i) {
            if (i == start || nums[i] != nums[i-1]) {
                vector<vector<int>> temp_ans;
                temp_ans = k_sum(nums, i + 1, target - nums[i], k -1);
                for (auto& row: temp_ans) {
                    row.insert(row.begin(), nums[i]);
                    ans.push_back(row);
                }
            }
        }
        return ans;
    }

    vector<vector<int>> two_pointer(vector<int>& nums, int start, long long target) {
        vector<vector<int>> ans;
        int low = start;
        int high = nums.size() - 1;
        
        while (low < high) {
            if (nums[low] + nums[high] == target) {
                ans.push_back({nums[low], nums[high]});
                ++low;
                while (low < nums.size() - 1 && nums[low] == nums[low - 1]) {
                    low++;
                }
            }
            else if (nums[low] + nums[high] > target) {
                high--;
            }
            else {
                low++;
            }
        }

        return ans;
    }
}