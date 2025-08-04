// https://leetcode.com/problems/remove-element/
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // return my_two_pointers(nums, val);
        return two_pointers_no_worry_about_order(nums, val);
    }

    // My Soln 
    // Two Pointers 
    // Time Complexity O(n)
    // Space Complexity O(1)
    int my_two_pointers(std::vector<int>& nums, int val) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        
        while (high < n) {
            if (nums[high] != val) {
                nums[low++] = nums[high];
            }
            high++;
        }
        return low;
    }

    // Two Pointers [optimized according to question]
    // Time Complexity O(n)
    // Space Complexity 
    int two_pointers_no_worry_about_order(std::vector<int>& nums, int val) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            if (nums[low] == val) {
                nums[low] = nums[high];
                high--;
            }
            else {
                low++;
            }
        }
        return low;
    }
};
