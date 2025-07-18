class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // return sorting(nums);
        return hashing(nums);
    }

    // Sorting
    // Time Complexity O(n * logn)
    // Space Complexity O(n)
    int sorting(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int longest = 0;
        int current = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i-1]) {
                if (nums[i] == nums[i-1] + 1) {
                        current++;
                }
                else {
                    longest = max(longest, current);
                    current = 1; 
                }
            }
        }
        return max(longest, current);
    }

    // Hashing
    // Time Complexity O(n)
    // Space Complexity O(n)
    int hashing(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int longest = 0;

        for (int e: uset) {
            if (!uset.count(e - 1)) {
                int e_copy = e;
                int current_longest = 1;
                while (uset.count(e_copy + 1)) {
                    current_longest++;
                    e_copy++;
                }
                longest = max(longest, current_longest);
            }
        }

        return longest;
    }
}