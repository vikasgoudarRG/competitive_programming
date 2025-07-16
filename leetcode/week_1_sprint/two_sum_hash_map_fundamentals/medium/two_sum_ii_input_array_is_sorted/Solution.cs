public class Solution {
    public int[] TwoSum(int[] numbers, int target) {
        // Time Complexity O(n)
        // Space Complexity O(1)
        int low = 0;
        int high = numbers.Length - 1;
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