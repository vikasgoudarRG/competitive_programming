// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // my soln
        return my_soln(prices);
    }

    // My Soln 
    // Time Complexity O(n)
    // Space Complexity O(1)
    int my_soln(const vector<int>& prices) {
        if (prices.empty()) return 0;

        int min_price_run = prices[0];
        int max_profit = 0;

        for (int elem: prices) {
            min_price_run = min(min_price_run, elem);
            max_profit = max(max_profit, elem - min_price_run);
        }

        return max_profit;
    }
};
