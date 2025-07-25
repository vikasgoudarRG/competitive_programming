class Solution {
public:
    bool isPalindrome(string s) {
        return two_pointers(s);
    }

    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    bool two_pointers(string s) {
        int n = s.length();
        int low = 0;
        int high = n - 1;

        while (low < high) {
            while (low < high && !isalnum(s[low])) {
                low++;
            }

            while (high > low && !isalnum(s[high])) {
                high--;
            }

            if (tolower(s[low]) != tolower(s[high])) {
                return false;
            }
            low++;
            high--;
        }

        return true;
    }
}