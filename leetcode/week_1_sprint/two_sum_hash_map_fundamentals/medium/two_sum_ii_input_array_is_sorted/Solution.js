/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    // Time Complexity O(n)
    // Space Complexity O(1)
    let low = 0;
    let high = numbers.length - 1;
    const ans = [-1, -1];

    while (low < high) {
        let sum = numbers[low] + numbers[high];
        if (sum == target) {
            ans[0] = low + 1;
            ans[1] = high + 1;
            break;
        }

        else if (sum > target) {
            --high;
        }

        else {
            ++low;
        }
    }

    return ans;
}