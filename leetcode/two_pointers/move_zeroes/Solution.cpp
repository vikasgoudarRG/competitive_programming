class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        two_pointers(nums);
    }

    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    void two_pointers(vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;

        while (slow < n && fast < n) {
            if (nums[slow] == 0) {
                fast = max(fast, slow + 1);
                while (fast < n) {
                    if (nums[fast] != 0) {
                        nums[slow] = nums[fast];
                        nums[fast] = 0;
                        break;
                    }
                    fast++;
                }
            }
            slow++;
        }
    }
}