class Solution {
public:
    void reverseString(vector<char>& s) {
        two_pointers(s);
    }

    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    void two_pointers(vector<char>& s) {
        int low = 0;
        int high = s.size() - 1;

        while (low < high) {
            char temp = s[low];
            s[low] = s[high];
            s[high] = temp;

            low++;
            high--;
        }
    }
}