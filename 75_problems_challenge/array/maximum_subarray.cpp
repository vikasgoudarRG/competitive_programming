// https://leetcode.com/problems/maximum-subarray/

class Solution {
    /*
    needed for 3rd method
private:
    vector<int> numsArray;
    */
public:
    int maxSubArray(vector<int>& nums) {
        /*
        numsArray = nums;
        return soln(0, nums.size() -1);
        */
        /*
        int curr_sum = 0;
        int max_sum = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            curr_sum = nums[i] + curr_sum;
            
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
            }

            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }

        return max_sum;
        */
        
        int curr_sum = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            curr_sum = max(nums[i], nums[i] + curr_sum);
            max_sum = max(curr_sum, max_sum);
        }

        return max_sum;
        
    }
    /*
    int soln(int L, int R) {
        if (L > R) {
            return INT_MIN;
        }
        int M = (L+R) / 2;

        int best_right = 0;
        int curr = 0;
        for (int i = M + 1; i <= R; ++i) {
            curr = numsArray[i] + curr;
            best_right = max(curr, best_right);
        }

        int best_left = 0;
        curr = 0;
        for (int i = M - 1; i >= L; --i) {
            curr = numsArray[i] + curr;
            best_left = max(curr, best_left);
        }

        int best_mixed = best_left + numsArray[M] + best_right;
        int left_half = soln(L, M - 1);
        int right_half = soln(M + 1, R);

        return max(best_mixed, max(left_half, right_half));
    }
    */
};
