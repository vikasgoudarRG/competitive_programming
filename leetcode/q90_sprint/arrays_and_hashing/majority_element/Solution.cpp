class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // return hashing(nums);
        // return sorting(nums);
        return boyer_moore_voting(nums);
    }

    // HashMap
    // Time Complexity O(n)
    // Space Complexity O(n)
    int hashing(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num: nums) {
            count[num]++;
        }

        // for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it)
        for (const auto& entry : count) {
            if (entry.second > nums.size() / 2) return entry.first;
        }

        return -1;
    }

    // Sorting
    // Time Complexity O(n)
    // Space Complexity O(n)
    int sorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    int boyer_moore_voting(vector<int>& nums) {
        int candidate;
        int count = 0;

        for (int num: nums) {
            if (count == 0) candidate = num;
            count += (num == candidate ? 1 : -1);
        }

        return candidate;
    }
}