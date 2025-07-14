#include <algorithm>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // return sol_1(nums);
        // return sol_2(nums);
        return sol_3(nums);
    } 

    // =======================================
    // Sol-1
    // Brute Force
    // Time Complexity O(n^2)
    // Space Complexity O(1)
    bool sol_1(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }    

    // =======================================
    // Sol-2
    // Sorting
    // Time Complexity O(n * log(n))
    // Space Complexity O(1)
    bool sol_2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
    
    // =======================================
    // sol-3
    // Set 
    // Time Complexity O(n) 
    // Space Complexity O(n) 
    bool sol_3(vector<int>& nums) {
        std::unordered_set<int> set;

        for (int i = 0; i < nums.size(); ++i) {
            if (set.find(nums[i]) != set.end()) {
                return true;
            }
            else {
                set.insert(nums[i]);
            }
        }
        return false;
    }
};