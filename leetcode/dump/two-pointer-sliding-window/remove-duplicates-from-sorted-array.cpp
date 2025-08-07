// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return my_two_pointers(nums);
    }

    // My Soln 
    // Two Pointers 
    // Time Complexity O(n)
    // Space Complexity O(1)
    int my_two_pointers(std::vector<int>& nums) {
        int n = nums.size();
        int slow = 0;
        int fast = 0;

        while (fast < n) {
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};
