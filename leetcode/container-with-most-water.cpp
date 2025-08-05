// https://leetcode.com/problems/container-with-most-water/

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        return my_two_pointers(height);
    }

    // My Soln
    // Two Pointers 
    // Time Complexity O(n)
    // Space Complexity O(1)
    int my_two_pointers(const vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;

        int ans = -1;
        while (low < high) {
            ans = max(
                ans, 
                (high - low) * min(height[high], height[low])
            );
            if (height[high] < height[low]) high--;
            else low++;
        }
        return ans;
    }
};
