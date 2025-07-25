class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        return two_pointer(nums);
    }

    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    vector<int> two_pointer(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int index = 0;
        vector<int> ans(n, 0);

        sort(nums.begin(), nums.end(), [](int& x, int& y) {
            return abs(x) < abs(y);
        });

        while (low <= high) {
            if (abs(nums[low]) < abs(nums[high])) {
                ans[index++] = static_cast<int>(pow(nums[low], 2));
                low++;
            }
            else {
                ans[index++] = static_cast<int>(pow(nums[high], 2));
                high--;
            }
        }

        return ans;
    }
}