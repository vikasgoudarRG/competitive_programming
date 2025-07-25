class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return two_pointers(nums, val);
    }

    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    int two_pointers(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        int n = nums.size();

        while (fast < n) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }
}