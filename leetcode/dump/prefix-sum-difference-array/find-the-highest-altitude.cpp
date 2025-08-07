// https://leetcode.com/problems/find-the-highest-altitude/

#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        return my_prefix_sum(gain);
    }

    // My Soln
    // Prefix 
    // Time Complexity O(n)
    // Space Complexity O(1)
    int my_prefix_sum(const vector<int>& gain) {
        int curr_height = 0;
        int max_height = 0;

        for (int elem: gain) {
            max_height = max(max_height, curr_height);
            curr_height += elem;
        }
        max_height = max(max_height, curr_height);

        return max_height;
    }
};
