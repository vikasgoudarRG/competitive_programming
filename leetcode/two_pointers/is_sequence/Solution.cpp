class Solution {
public:
    bool isSubsequence(string s, string t) {
        return two_pointers(s, t);
    }

    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    bool two_pointers(string s, string t) {
        int read_s = 0;
        int read_t = 0;

        int len_s = s.length();
        int len_t = t.length();

        while (read_t < len_t && read_s < len_s) {
            if (s[read_s] == t[read_t]) {
                read_s++;
            }
            read_t++;
        }
        return read_s == len_s;
    }
}