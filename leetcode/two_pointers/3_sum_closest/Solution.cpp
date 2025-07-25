class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return three_pointers(nums, target);
    }

    // Three Pointers
    // Time Complexity O(n * n)
    // Space Complexity O(n) or O(log n), depends on sorting algorithm
    int three_pointers(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            diff = _two_pointers(i, target, nums, diff);
        }

        return target - diff;
    }

    int _two_pointers(int index, int target, vector<int>& nums, int diff) {
        int low = index + 1;
        int high = nums.size() - 1;

        while (low < high) {
            int sum = nums[index] + nums[low] + nums[high];
            if (abs(target - sum) < abs(diff)) {
                diff = target - sum;
            }

            if (nums[index] + nums[low] + nums[high] < target) {
                low++;
            }

            else if (nums[index] + nums[low] + nums[high] > target) {
                high--;
            }

            else {
                diff = 0;
                break;
            }
        }
        return diff;
    }
}