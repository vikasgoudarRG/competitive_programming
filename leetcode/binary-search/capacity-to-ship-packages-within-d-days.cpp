// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

#include <vector>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        return my_binary_search(weights, days);
    }

    // My Soln
    // Binary search the solution
    // Time Complexity O(logn * n)
    // Space Complexity O(1)
    int my_binary_search(const vector<int>& weights, int days) {
        int low = weights[0];
        int high = weights[0];

        for (int weight: weights) {
            low = max(low, weight);
            high += weight;
        }

        // FFFFFFFFTTTTTTTTT
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (!is_solution(mid, weights, days)) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }

    bool is_solution(int ship_capacity, const vector<int>& weights, int days_limit) {
        int days_run = 1;
        int weight_run = 0;
        for (int weight: weights) {
            if (weight + weight_run > ship_capacity) {
                days_run++;
                weight_run = 0;
            }
            weight_run += weight;
        }
        return days_run <= days_limit;
    }
};
