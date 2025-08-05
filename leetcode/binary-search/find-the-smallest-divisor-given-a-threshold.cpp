// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

#include <vector>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        return my_binary_search(nums, threshold);
    }

    // My Soln
    // Binary Search the solution
    // Time Complexity O(logn * n)
    // Space Complexity O(1)
    int my_binary_search(const vector<int>& nums, int threshold) {
        int low = 1;
        int high = nums[0];
        for (int elem: nums) high = max(high, elem);

        // FFFFFFFFTTTTTTT
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (!is_solution(mid, nums, threshold)) {
                low = mid + 1;
            }
            else high = mid;
        }
        return low;
    }

    bool is_solution(int divisor, const vector<int>& nums, int threshold) {
        int div_run = 0;
        for (int elem: nums) {
            div_run += (elem + divisor - 1) / divisor;
        }
        return div_run <= threshold;
    }
};

