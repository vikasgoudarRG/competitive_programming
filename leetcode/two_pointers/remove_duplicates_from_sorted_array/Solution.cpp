class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return two_pointers(nums);
    }

    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    int two_pointers(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = 0;

        while (high < n) {
            if (nums[high] != nums[low]) {
                nums[++low] = nums[high];
            }
            high++;
        }

        return ++low;
    }
}