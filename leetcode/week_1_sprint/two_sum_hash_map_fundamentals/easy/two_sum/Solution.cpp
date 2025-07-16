class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Time Complexity O(n)
        // Space Complexity O(n)

        unordered_map<int, int> hash_map;
        vector<int> ans = {-1, -1};

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash_map.count(complement) != 0) {
                ans[0] = hash_map[complement];
                ans[1] = i;
                break;
            }

            else {
                hash_map[nums[i]] = i;
            }
        }

        return ans;
    }
};