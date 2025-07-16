package week_1_sprint.two_sum_hash_map_fundamentals.medium.two_sum_ii_input_array_is_sorted;

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        // Time Complexity O(n)
        // Space Complexity O(1)
        int low = 0;
        int high = numbers.length - 1;
        int[] ans = {-1, -1};

        while (low < high) {
            int sum = numbers[low] + numbers[high];

            if (sum == target) {
                ans[0] = low + 1;
                ans[1] = high + 1;
                break;
            } 
            
            else if (sum > target) {
                high--;
            }

            else {
                low++;
            }
        }
        return ans;
    }
}