// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Linear Search 
        // Time Complexity O(n^2)
        /*
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
        */

        // Sort and Search
        // Time Complexity O( n * log(n) )
        /* 
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] == nums[i]) return true;
        }
        return false;
        */

        // unordered_set (hash based)
        // Time Complexity O(n)
        // In practice can be slower than sorting since hashing involves a lot of backend operations
        // like hashing and collision control
        unordered_set<int> hash_set;
        for (int num: nums) {
            if (hash_set.count(num)) {
                return true;
            }
            hash_set.insert(num);
        }
        return false;
    } 
};