// https://leetcode.com/problems/sort-colors/

#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        three_pointers(nums);       
    }

    // Three Pointers 
    // Time Complexity O(n)
    // Space Complexity O(1)
    void three_pointers(vector<int>& nums) {
        int lp = 0;
        int rp = nums.size() - 1;
        int p = 0;

        while (p <= rp) {
            if (nums[p] == 2) {
                swap(nums[p], nums[rp--]);
            }
            else if (nums[p] == 0) {
                swap(nums[p++], nums[lp++]);
            }
            else {
                p++;
            }
        }
    }
};
