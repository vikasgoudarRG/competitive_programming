/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    // Time Complexity O(n)
    // Space Complexity O(1)
    const map = new Map();
    const ans = [-1, -1];

    for (let i = 0; i < nums.length; ++i) {
        const complement = target - nums[i];
        if (map.has(complement)) {
            ans[0] = map.get(complement);
            ans[1] = i;
            break;
        }

        else {
            map.set(nums[i], i);
        }
    }

    return ans;
}