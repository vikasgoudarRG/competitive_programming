// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0;
        int R = nums.size() - 1;

        if (nums[L] < nums[R]) {
            return nums[L];
        }

        while (L < R) {
            int M = L + (R-L)/2;
            if (nums[M] > nums[R]) {
                L = M + 1;
            }
            else {
                R = M;
            }
        }

        return nums[L];
    }
};
