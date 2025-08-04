// https://leetcode.com/problems/reverse-string/description/
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        return my_two_pointers(s);
    }
    
    // My Soln 
    // Two Pointers 
    // Time Complexity O(n)
    // Space Complexity O(1)
    void my_two_pointers(vector<char>& s) {
        int n = s.size();
        int low = 0;
        int high = n - 1;

        while (low < high) {
            char temp = s[low];
            s[low] = s[high];
            s[high] = temp;

            low++;
            high--;
        }
    }
};
