// https://leetcode.com/problems/minimum-window-substring/

#include <string>
#include <unordered_map>
#include <climits>
#include <utility>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        // return sliding_window(s, t);
        return optimized_sliding_window(s, t);
    }

    // Sliding Window 
    // Time Complexity O(t + 2s) // O(n)
    //                  where n -> size of s
    //                        m -> size of t
    // Space Complexity O(s + n) // O(n)
    string sliding_window(const string& s, const string& t) {
        int s_length = s.length();

        unordered_map<char, int> t_char_freq;
        for (char c: t) t_char_freq[c]++;

        int num_unique_chars = t_char_freq.size();

        int low = 0;
        int high = 0;
        int smallest_valid_substring = s_length + 1;
        int left_indice_svs = -1;

        unordered_map<char, int> run_char_freq;
        int run_formed = 0;

        while (high < s_length) {
            char c = s[high];
            run_char_freq[c]++;

            if (t_char_freq.count(c) && run_char_freq[c] == t_char_freq[c]) run_formed++;   

            while (run_formed == num_unique_chars) {
                if (high - low + 1 < smallest_valid_substring) {
                    smallest_valid_substring = high - low + 1;
                    left_indice_svs = low;
                } 

                run_char_freq[s[low]]--;

                if (t_char_freq.count(s[low]) && run_char_freq[s[low]] < t_char_freq[s[low]]) {
                    run_formed--;
                }
                low++;
            }
            high++;
        }
        return left_indice_svs == -1 ? "" : s.substr(left_indice_svs, smallest_valid_substring);
    }

    // Optimized Sliding Window
    // It is optimized for cases where len(t) <<< len(s)
    // So prefiltering s, can save time 
    // Time Complexity O(n + 2f + m) // O(n + m) // O(n)
    // Space Complexity 
    string optimized_sliding_window(const string& s, const string& t) {
        unordered_map<char, int> t_char_freq;
        for (char c: t) t_char_freq[c]++;
        int count_needed = t_char_freq.size();

        vector<pair<char, int>> s_filtered;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (t_char_freq.count(c)) {
                s_filtered.push_back({c, i});
            }
        }

        unordered_map<char, int> s_filtered_run_char_freq;
        int run_count = 0;
        int s_filtered_len = s_filtered.size();
        int low = 0;
        int high = 0;

        int min_valid_substring = INT_MAX;
        int mvs_left_indice = -1;
        while (high < s_filtered_len) {
            char c = s_filtered[high].first;
            s_filtered_run_char_freq[c]++;
            if (s_filtered_run_char_freq[c] == t_char_freq[c]) {
                run_count++;
            }

            while (run_count == count_needed) {
                char c = s_filtered[low].first;
                if (s_filtered[high].second - s_filtered[low].second + 1 < min_valid_substring) {
                    min_valid_substring = s_filtered[high].second - s_filtered[low].second + 1;
                    mvs_left_indice = s_filtered[low].second;
                }
                if (s_filtered_run_char_freq[c] == t_char_freq[c]) {
                    run_count--;
                }
                s_filtered_run_char_freq[c]--;
                low++;
            }
            high++;
        }
        return mvs_left_indice == -1 ? "" : s.substr(mvs_left_indice, min_valid_substring);
    }
};
