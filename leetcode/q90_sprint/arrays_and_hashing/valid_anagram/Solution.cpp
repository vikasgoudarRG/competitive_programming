class Solution {
public:
    bool isAnagram(string s, string t) {
        // return sorting(s, t);
        return hashing(s, t);
    }

    // Sorting
    // Time Complexity O(n * logn)
    // Space Complexity O(n)
    bool sorting(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }

    // Hashing
    // Time Complexity O(n)
    // Space Complexity O(n)
    bool hashing(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        std::unordered_map<char, int> count;

        for (char c : s) {
            count[c]++;
        }

        for (char c: t) {
            if (count.find(c) == count.end()) return false;
            count[c]--;
            if (count[c] == 0) {
                count.erase(c);
            }
        }

        return count.empty();
    }
}