// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // return my_sliding_window(s);
        // return optimized_sliding_window(s);
        return array_optimized_sliding_window(s);

    }


    // My Soln 
    // Time Complexity O(2*n) = O(n)
    // Space Complexity O( min(m, n) )
    //                  where m -> size of charset
    //                        n -> size of string
    int my_sliding_window(const string& s) {
        int n = s.length();
        unordered_set<char> seen;

        int low = 0;
        int high = 0;
        int longest_length = 0;

        while (high < n) {
            while (low < high && seen.count(s[high])) {
                seen.erase(s[low]);
                low++;
            }
            seen.insert(s[high]);

            longest_length = max(longest_length, high - low + 1);
            high++;
        }

        return longest_length;
    }

    // Optimized Sliding Window 
    // Time Complexity O(n)
    // Space Complexity O(min(n, m))
    //                  where m -> size of charset
    //                        n -> size of string 
    int optimized_sliding_window(const string& s) {
        int n = s.length();
        int low = 0;
        int high = 0;

        unordered_map<char, int> indices;
        int longest_substring = 0;

        while (high < n) {
            char curr = s[high];
            if (indices.count(curr) && indices[curr] >= low) {
                low = indices[curr] + 1;
            }
            indices[curr] = high;
            longest_substring = max(
                longest_substring, 
                high - low + 1
            );

            high++;
        }

        return longest_substring;
    }

    // If charset is small, we can use arrays to simulate maps/ sets 
    // Time Complexity O(n)
    // Space Complexity O(m), where m -> size of char set 
    int array_optimized_sliding_window(const string& s) {
        vector<int> indice_map(128, -1);

        int low = 0;
        int high = 0;
        int n = s.length();

        int longest_substring = 0;
        while (high < n) {
            char curr = s[high];

            if (indice_map[curr] != -1 && indice_map[curr] >= low) {
                low = indice_map[curr] + 1;
            }
            indice_map[curr] = high;

            longest_substring = max(
                longest_substring, 
                high - low + 1
            );
            high++;
        }
        return longest_substring;
    }
};
