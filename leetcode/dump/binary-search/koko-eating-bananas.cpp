// https://leetcode.com/problems/koko-eating-bananas/

#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return my_binary_soln(piles, h);
    }

    // My Soln
    // Binary Search the answer 
    // Time Complexity O(n * logn)
    // Space Complexity O(1)
    int my_binary_soln(const vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (int elem: piles) {
            high = max(high, elem);
        }

        // FFFFFFTTTTTTT
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (!is_solution(mid, piles, h)) {
                low = mid + 1;
            } 
            else {
                high = mid;
            }
        }
        return low;
    }

    bool is_solution(int per_hour_rate, const vector<int>& piles, int h) {
        int time_needed = 0;
        for (int elem: piles) {
            time_needed += (elem + per_hour_rate - 1) / per_hour_rate;
        }
        return time_needed <= h;
    }
};
