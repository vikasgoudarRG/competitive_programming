// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <vector>
#include <string>
#include <iostream> 
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        return my_sliding_window(s, words);
    }

private:
    /**
     * @brief - sliding window to keep track of words, when new word reset window
     * @param s - string to check for concatenations of all words
     * @param words - vector of string, each string is a word which we need
     * @return - vector of integers, where each element is the starting index of a substring of combination of words needed
     */
    // Time Complexity O(k + k * n/k * 2)
    // Space Complexity O(2*w)
    // where w -> len of words
    // where k -> len of word
    // where s -> len of string s
    std::vector<int> my_sliding_window(const std::string& s, const std::vector<std::string>& words) {
        std::vector<int> ans;

        std::unordered_map<std::string, int> word_freq;
        int total_words = 0;
        for (std::string word: words) {
            word_freq[word]++;
            total_words++;
        }
        int unique_word_count = word_freq.size();


        int word_length = words[0].length();
        int s_len = s.length();
        for (int start = 0; start < word_length; ++start) {
            std::unordered_map<std::string, int> run_word_freq;
            int word_freq_fulfilled = 0;

            // sliding window from start with string size word_length
            int low = start;
            int high = start;
            while (high <= s_len - word_length) {
                std::string word = s.substr(high, word_length);
                if (word_freq.count(word)) {
                    run_word_freq[word]++;
                
                    if (run_word_freq[word] == word_freq[word]) {
                        word_freq_fulfilled++;
                    }
                    while ( ((high + word_length - low) / word_length) >  total_words) {
                        std::string low_word = s.substr(low, word_length);
                        if (word_freq.count(low_word)) {
                            if (run_word_freq[low_word] == word_freq[low_word]) {
                                word_freq_fulfilled--;
                            }
                            run_word_freq[low_word]--;
                        }
                        low += word_length;
                    }

                    if (word_freq_fulfilled == unique_word_count) {
                        ans.push_back(low);
                    }
                }
                else {
                    run_word_freq.clear();
                    word_freq_fulfilled = 0;
                    low = high + word_length;
                }
                high += word_length;
            }
        }

        return ans;
    }
};
