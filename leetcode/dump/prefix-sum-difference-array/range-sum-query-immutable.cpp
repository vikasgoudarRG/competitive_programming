// https://leetcode.com/problems/range-sum-query-immutable/

#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> prefix_sum;
public:
    NumArray(vector<int>& nums) {
        // making prefix_sum
        prefix_sum.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left];
    }
};
// Soln 
// Time Complexity O(k * n)
// Space Complexity O(n)

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
