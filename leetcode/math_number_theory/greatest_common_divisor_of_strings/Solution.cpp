class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // return brute_force(str1, str2);
        return gcdMethod(str1, str2);
    }

    // Brute Force
    // Time Complexity O(min(n, m) * (n + m))
    // Space Complexity O(1)
    string brute_force(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        
        for (int len = min(len1, len2); len >= 1; --len) {
            if (is_gcd_string(str1, str2, len)) {
                return str1.substr(0, len);
            }
        }
        return "";
    }
    bool is_gcd_string(string str1, string str2, int len) {
        int len1 = str1.length();
        int len2 = str2.length();

        if (len1 % len != 0 || len2 % len != 0) return false;

        // taking str1 as base for both str1 and str2
        for (int i = 0; i < len1; ++i) {
            if (str1[i] != str1[i % len]) {
                return false;
            }
        }
        for (int i = 0; i < len2; ++i) {
            if (str2[i] != str1[i % len]) {
                return false;
            }
        }
        return true;
    }

    // Gcd
    // Time Complexity O(n + m)
    // Space Complexity O(1)
    string gcdMethod(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        return str1.substr(0, gcd(str1.length(), str2.length()));

    }
}