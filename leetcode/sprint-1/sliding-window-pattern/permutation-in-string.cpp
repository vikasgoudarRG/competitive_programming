// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        return sliding_window(s1, s2);
    }

private:
    // Sliding Window 
    // Time Complexity O(m + n*2)
    // Space Complexity O(2*m)
    // where m -> length of string s1
    // where n -> length of string s2
    bool sliding_window(const std::string& s1, const std::string& s2) {
        std::unordered_map<char, int> s1_char_freq;
        for (char c: s1) {
            s1_char_freq[c]++;
        }
        int s1_len = s1.length();
        int s1_unique_chars = s1_char_freq.size(); 

        std::unordered_map<char, int> s2_run_char_freq;
        int low = 0;
        int high = 0;
        int s2_len = s2.size();
        int chars_formed = 0;
        while (high < s2_len) {
            char char_high = s2[high];

            if (s1_char_freq.find(char_high) != s1_char_freq.end()) {
                s2_run_char_freq[char_high]++;
                if (s2_run_char_freq[char_high] == s1_char_freq[char_high]) {
                    chars_formed++;
                }

                while (high - low + 1 > s1_len) {
                    char char_low = s2[low];
                    if (s2_run_char_freq[char_low] == s1_char_freq[char_low]) {
                        chars_formed--;
                    }
                    s2_run_char_freq[char_low]--;
                    low++;
                }

                if (chars_formed == s1_unique_chars) return true;
            }
            else {
                low = high + 1;
                chars_formed = 0;
                s2_run_char_freq.clear();
            }
            high += 1;
        }
        return false;
    }
};
