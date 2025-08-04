// https://leetcode.com/problems/valid-palindrome/description/
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // return my_two_pointers(s);
        // return reverse_compare(s);
        return two_pointers(s);
    }

    // My Soln
    // Two Pointers 
    // Time Complexity O(n)
    // Space Complexity O(1)
    bool my_two_pointers(const string& s) {
        int n = s.length();

        int low = 0;
        int high = n - 1;

        while (low < high) {
            if (!isalnum(s[low])) {
                low++;
            }
            else if (!isalnum(s[high])) {
                high--;
            }
            else {
                if (tolower(s[low]) != tolower(s[high])) {
                    return false;
                }
                else {
                    low++;
                    high--;
                }
            }
        }
        return true;
    }

    // Reverse 
    // Time Complexity O(n)
    // Space Complexity O(n)
    bool reverse_compare(const string& s) {
        string sf = "";
        for (char c: s) {
            if (isalnum(c)) {
                sf += tolower(c);
            }
        }

        const string sr = string(sf.rbegin(), sf.rend());
        
        return sf == sr;
    }

    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    bool two_pointers(const string& s) {
        int n = s.length();
        int low = 0;
        int high = n - 1;

        // just practicing for loop
        // for (int low = 0, int high = s.length() - 1; low < high; low++, high--)
        while (low < high) {
            while (low < high && !isalnum(s[low])) low++;
            while (low < high && !isalnum(s[high])) high--;

            if (tolower(s[low]) != tolower(s[high])) return false;
            low++;
            high--;
        }
        return true;
    }
};