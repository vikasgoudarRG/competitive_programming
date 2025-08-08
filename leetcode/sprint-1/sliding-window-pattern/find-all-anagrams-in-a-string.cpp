// https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include <vector>
#include <unordered_map>
#include <array>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // return sliding_window(s, p);
        return sliding_window_optimized(s, p);
    }

    // Sliding Window 
    // Time Complexity O(p + s)
    // Time Complexity O(2*p) // O(p)
    vector<int> sliding_window(const string& s, const string& p) {
        unordered_map<char, int> p_char_freq;
        int p_char_total = 0;
        for (char c: p) {
            p_char_freq[c]++;
            p_char_total++;
        }
        int needed = p_char_freq.size();

        int low = 0;
        int high = 0;
        int n = s.size();    
        unordered_map<char, int> s_run_char_freq;
        int run_needed = needed;

        vector<int> res;

        while (high < n) {
            char c = s[high];
            if (p_char_freq.count(c)) {
                s_run_char_freq[c]++;
                if (s_run_char_freq[c] == p_char_freq[c]) {
                    run_needed--;
                }
            }

            while (high - low + 1 > p_char_total) {
                char c_low = s[low];\
                if (s_run_char_freq.count(c_low)) {
                    if (s_run_char_freq[c_low] == p_char_freq[c_low]) {
                        run_needed++;
                    }
                    s_run_char_freq[c_low]--;
                }
                low++;
            }
            if (run_needed == 0) {
                res.push_back(low);
            }
            high++;
        }

        return res;
    }

    // Sliding Window Optimized 
    // Since key-space is small (26 letters)
    // We can replace hash with array 
    // Time Complexity 
    // Space Complexity 
    vector<int> sliding_window_optimized(const string& s, const string& p) {
        array<int, 26> p_char_freq;
        p_char_freq.fill(0);
        int p_char_total = 0;
        int needed = 0;
        for (char c: p) {
            if (p_char_freq[c-'a'] == 0) {
                needed++;
            }
            p_char_freq[c - 'a']++;
            p_char_total++;
        }

        array<int, 26> s_run_char_freq;
        s_run_char_freq.fill(0);

        vector<int> ans;

        int low = 0;
        int high = 0;
        int n = s.size();

        while (high < n) {
            char c = s[high];
            int c_index = c - 'a';

            if (p_char_freq[c_index] != 0) {
                s_run_char_freq[c_index]++;
                if (s_run_char_freq[c_index] == p_char_freq[c_index]) {
                    needed--;
                }
            }

            while (high - low + 1 > p_char_total) {
                char c_low = s[low];
                int c_low_index = c_low - 'a';

                if (p_char_freq[c_low_index] != 0) {
                    if (s_run_char_freq[c_low_index] == p_char_freq[c_low_index]) {
                        needed++;
                    }
                    s_run_char_freq[c_low_index]--;
                }
                low++;
            }
            if (needed == 0) {
                ans.push_back(low);
            }
            high++;
        }
        return ans;
    }
};
