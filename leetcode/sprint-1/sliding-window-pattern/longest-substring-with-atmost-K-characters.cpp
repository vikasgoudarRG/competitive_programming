// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

#include <algorithm>
#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(std::string s, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        // return my_sliding_window(s, k);
        return binary_search(s, k);
    }

private:
    /**
     * @brief - sliding window to maintain max distinct as k, otherwise shortening  it
     * @param s - input string s
     * @param k - at max k occurcence
     * @return - longest substring with at most k distinct characters
     */
     // Time Complexity O(2*s), where s -> length of string
     // Space Complexity O(s)
    int my_sliding_window(const std::string& s, const int k) {
        std::unordered_map<char, int> run_char_freq;
        int s_len = s.length();
        int longest_sstr_k = 0;

        int low = 0;
        int high = 0;
        while (high < s_len) {
            char c_high = s[high];
            run_char_freq[c_high]++;

            while (run_char_freq.size() > k) {
                char c_low = s[low];
                if (--run_char_freq[c_low] == 0) {
                    run_char_freq.erase(c_low);
                }
                low++;
            }

            longest_sstr_k = std::max(
                longest_sstr_k,
                high - low + 1
            );

            high++;
        }
        return longest_sstr_k;
    }

    // Binary Search on Sliding Window 
    // Time Complexity O(log n * n)
    // Space Complexity O(n)
    // TTTTTFFFFF
    int binary_search(const std::string& s, int k) {
        int n = s.size();
        int low = k;
        int high = n + 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isValid(s, k, mid)) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        low--;
        return low;
    }

    bool isValid(const std::string& s, int max_distinct, int substring_length) {
        std::unordered_map<char, int> run_char_freq;
        
            
        int low = 0;
        int high = 0;
        int s_len = s.length();

        while (high < s_len) {
            char curr_char = s[high];
            run_char_freq[curr_char]++;

            while (high - low + 1 > substring_length) {
                char char_low = s[low];
                if (--run_char_freq[char_low] == 0) {
                    run_char_freq.erase(char_low);
                }
                low++;
            }

            if (high - low + 1 == substring_length) {
                if (run_char_freq.size() <= max_distinct) return true;
            }
            high++;
        }

        return false;
    }
};
