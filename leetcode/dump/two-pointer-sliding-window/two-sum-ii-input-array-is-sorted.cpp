// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // return my_two_pointers(numbers, target);
        
    }

    // My Soln
    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    vector<int> my_two_pointers(const std::vector<int>& numbers, int target) {
        int n = numbers.size();
        int low = 0;
        int high = n - 1;

        while (low < high) {
            if (numbers[low] + numbers[high] == target) {
                return {low + 1, high + 1};
            }
            else if (numbers[low] + numbers[high] > target) {
                high--;
            }
            else {
                low++;
            }
        }
        return {-1, -1};
    }

};