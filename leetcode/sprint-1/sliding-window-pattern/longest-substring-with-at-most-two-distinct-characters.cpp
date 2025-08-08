// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/

#include <unordered_map>
#include <string>
#include <algorithm>


class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(std::string s) {
        // return my_sliding_window(s);
        return my_binary_search(s);
    }

private:
    // My Soln 
    // Sliding Window 
    // Time Complexity O(2*n)
    // Space Complexity O(1)
    int my_sliding_window(const std::string& s) {
        std::unordered_map<char, int> run_char_freq;
        int n = s.length();

        int low = 0;
        int high = 0;
        int longest_substring_satisfy = 0;
        while (high < n) {
            char curr_char = s[high];
            run_char_freq[curr_char]++;

            while (run_char_freq.size() > 2) {
                char char_low = s[low];
                if (--run_char_freq[char_low] == 0) run_char_freq.erase(char_low);
                low++;
            }
            longest_substring_satisfy = std::max(
                longest_substring_satisfy, 
                high - low + 1
            );
            high++;
        }

        return longest_substring_satisfy;
    }

    // My Soln
    // Binary Search 
    // Time Complexity O(logn * 2*n)
    // Space Complexity O(1)
    int my_binary_search(const std::string& s) {
        int n = s.length();
        if (n < 2) return n;

        int low = 2; // magic number given in question
        int high = n;
        // TTTTTTFFFFF
        while (low < high) {
            int middle = low + (high - low + 1) / 2;
            if (is_valid(s, middle, 2)) { // Magic number: 2 -> given in question 
                low = middle;
            }
            else {
                high = middle - 1;
            }
        }
        return low;
    }

    bool is_valid(const std::string& s, int substring_length, int max_distinct) {
        int low = 0;
        int high = 0;
        int s_len = s.length();
        std::unordered_map<char, int> run_char_freq;

        while (high < s_len) {
            char char_high = s[high];
            run_char_freq[char_high]++;

            while (high - low + 1 > substring_length) {
                char char_low = s[low];
                if (--run_char_freq[char_low] == 0) {
                    run_char_freq.erase(char_low);
                }
                low++;
            }
            if (high - low + 1 == substring_length) {
                if (run_char_freq.size() <= max_distinct) { 
                    return true;
                }
            }
            high++;
        }
        return false;
    }
};
