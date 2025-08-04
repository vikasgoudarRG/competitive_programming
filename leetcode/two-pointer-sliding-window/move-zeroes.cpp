// https://leetcode.com/problems/move-zeroes/description/
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // return my_two_pointers(nums);
        return two_pointers(nums);
    }

    // My Soln
    // Two Pointers 
    // Time Complexity O(n)
    // Space Complexity O(1)
    void my_two_pointers(std::vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;

        while (fast < n) {
            while (slow < n && nums[slow] != 0) {
                slow++;
            }
            fast = max(fast, slow);

            while (fast < n && nums[fast] == 0) {
                fast++;
            }

            if (slow >= n || fast >= n) break;
            
            nums[slow] = nums[fast];
            nums[fast] = 0;
        }
    }

    // Two Pointers 
    // Time Complexity O(n)
    // Space Complexity O(1)
    void two_pointers(std::vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;

        while (fast < n) {
            if (nums[fast] != 0) {
                int temp = nums[slow];
                nums[slow++] = nums[fast];
                nums[fast] = temp;
            }
            fast++;
        }
        /*
        for (int i = slow; i < n; ++i) {
            nums[i] = 0;
        }
        */
    }
}