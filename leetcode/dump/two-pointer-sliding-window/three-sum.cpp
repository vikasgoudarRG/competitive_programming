// https://leetcode.com/problems/3sum/

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return my_three_pointers(nums);
        // return hashing_memory(nums);
    }

    // My Soln
    // Three Pointers 
    // Time Complexity O(n ^ 2)
    // Space Complexity O(n) // since we sort (modify) input array
    vector<vector<int>> my_three_pointers(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int indice = 0;
        while (indice < n) {
            if (nums[indice] > 0) break;
            if (indice == 0 || nums[indice] != nums[indice - 1]) {
                my_two_sum_helper(nums, indice, ans);
            }
            indice++;
        }

        return ans;
    }

    void my_two_sum_helper(const vector<int>& nums, int indice, vector<vector<int>>& ans) {
        int low = indice + 1;
        int high = nums.size() - 1;

        while (low < high) {
            if (nums[indice] + nums[low] + nums[high] == 0) {
                ans.push_back({nums[indice], nums[low], nums[high]});
                low++;
                while (low < high && nums[low] == nums[low - 1]) {
                    low++;
                }
            }
            else if (nums[indice] + nums[low] + nums[high] > 0) {
                high--;
            }
            else {
                low++;
            }
        }
    }

    // Hashing Memory 
    // Time Complexity O(n ^ 2)
    // Space Complexity O(n)
    vector<vector<int>> hashing_memory(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int indice = 0;
        while (indice < n) {
            if (nums[indice] > 0) break;
            if (indice == 0 || nums[indice] != nums[indice - 1]) {
                two_sum_hashing_helper(nums, indice, ans);
            }
            indice++;
        }
        return ans;
    }

    void two_sum_hashing_helper(const vector<int>& nums, int indice, vector<vector<int>>& ans) {
        unordered_set<int> seen;

        int low = indice + 1;

        while (low < nums.size()) {
            int complement = -(nums[indice] + nums[low]);
            if (seen.count(complement)) {
                ans.push_back({nums[indice], complement, nums[low]});
                
                low++;
                while (low < nums.size() && nums[low] == nums[low - 1]) low++;
            }
            else {
                seen.insert(nums[low]);
                low++;
            }
        }
    }
};
