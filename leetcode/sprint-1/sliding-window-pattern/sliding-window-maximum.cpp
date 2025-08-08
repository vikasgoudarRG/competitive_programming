// https://leetcode.com/problems/sliding-window-maximum/description/

#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        return sliding_window(nums, k);
    }

private:
    // Sliding Window 
    // Time Complexity O(n)
    // Space Complexity O(k), where k is size of window
    vector<int> sliding_window(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        int n = nums.size();
        for (int i = k; i < n; ++i) {
            if (dq.front() < i - k + 1) { 
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);

            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
