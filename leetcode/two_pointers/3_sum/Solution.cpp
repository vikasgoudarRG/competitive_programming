class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return three_pointers(nums);
    }

    // Three Pointers
    // Time Complexity O(n ^ 2)
    // Space Complexity O(1)
    vector<vector<int>> three_pointers(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int index = 0;
        int n = nums.size();
        vector<vector<int>> ans;

        while (index < n) {
            if (nums[index] > 0) {
                break;
            }
            if (index == 0 || nums[index] != nums[index - 1]) {
                _support_two_pointers(index, nums, ans);
            }
            index++;
        }

        return ans;
    }

    void _support_two_pointers(int index, vector<int>& nums, vector<vector<int>>& ans) {
        int n = nums.size();
        int low = index + 1;
        int high = n - 1;
        int first = nums[index];

        while (low < high) {
            if (first + nums[low] + nums[high] > 0) {
                high--;
            }
            else if (first + nums[low] + nums[high] < 0) {
                low++;
            }
            else {
                ans.push_back({nums[index], nums[low], nums[high]});
                low++;
                while (low < high && nums[low] == nums[low - 1]) {
                    low++;
                }
            }
        }
    }
}