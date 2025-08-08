// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        // return sliding_window(s, k);
        return binary_search_on_sliding_window(s, k);
    }

    // sliding window 
    // time complexity O(2*n) // O(n)
    // space complexity O(n)
    int sliding_window(const std::string& s, int k) {
        int s_len = s.length();
        int longest_substring = 0;

        std::unordered_map<char, int> run_freq;
        int most_freq_char_count = 0;
        int low = 0;
        int high = 0;

        while (high < s_len) {
            char char_high = s[high];
            run_freq[char_high]++;
            if (most_freq_char_count < run_freq[char_high]) {
                most_freq_char_count = run_freq[char_high];
            }
            
            while (high - low + 1 - most_freq_char_count > k) {
                char char_low = s[low];
                run_freq[char_low]--;
                low++;
            }
            longest_substring = std::max(longest_substring, high - low + 1);
            high++;
        }

        return longest_substring;
    }

    // Binary search on sliding window 
    // Time complexity O(logn * 2n)
    // Space Complexity O(n)
    // TTTTTFFFFFF
    int binary_search_on_sliding_window(const std::string& s, int k) {
        int s_len = s.length();
        int low = k;
        int high = s_len;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (is_valid(s, k, mid)) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }

    bool is_valid(const std::string& s, int k, int substring_length) {
        std::unordered_map<char, int> run_freq;
        int most_freq_char_count = 0;
        int low = 0;
        int high = 0;
        int longest_substring = 0;
        int s_len = s.length();

        while (high < s_len) {
            char char_high = s[high];
            run_freq[char_high]++;

            while (high - low + 1 > substring_length) {
                char char_low = s[low];
                run_freq[char_low]--;
                low++;
            }

            if (run_freq[char_high] > most_freq_char_count) {
                most_freq_char_count = run_freq[char_high];
            }

            if (substring_length - most_freq_char_count <= k) return true;
            high++;
        }
        return false;
    }
};
