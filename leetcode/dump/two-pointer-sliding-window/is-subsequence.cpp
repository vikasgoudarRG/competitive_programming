// https://leetcode.com/problems/is-subsequence/description/
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // return my_two_pointers(s, t);
        // return tail_recursion(0, 0, s, t);
        // return hashing(s, t);
        return dp(s, t);
    }

    // My Soln
    // Two Pointers 
    // Time Complexity O(n)
    // Space Complexity O(1)
    bool my_two_pointers(const string& s, const string& t) {
        int sp = 0;
        int tp = 0;

        int sn = s.length();
        int tn = t.length();

        while (sp < sn && tp < tn) {
            if (t[tp] == s[sp]) {
                sp++;
            }
            tp++;
        }

        return sp == sn;
    }

    // Tail Recursion 
    // Time Complexity O(n)
    // Space Complexity O(n) 
    //                  O(1) if tail recursion is optimised such as in languages like c++
    bool tail_recursion(int sp, int tp, const string& s, const string& t) {
        if (sp == s.size()) return true;
        if (tp == t.size()) return false;

        if (s[sp] == t[tp]) sp++;
        tp++;
        return tail_recursion(sp, tp, s, t);
    }
    
    // Hashing 
    //      Optimum for mutliple queries with target being same, solves bottle neck of 
    //      needing to loop through target every time 
    // Time Complexity O(n + n*logn)
    // Space Complexity O(n)
    bool hashing(const string& s, const string& t) {
        unordered_map<char, vector<int>> hash_map;

        for (int i = 0; i < t.size(); ++i) {
            char c = t[i];
            hash_map[c].push_back(i);
        }

        int min_upper_bound = -1;
        for (char c: s) {
            if (!hash_map.count(c)) return false;
                
            vector<int> indices = hash_map[c];
            vector<int>::iterator it = upper_bound(indices.begin(), indices.end(), min_upper_bound);

            if (it == indices.end()) return false;

            min_upper_bound = *it;
        }

        return true;
    }

    // Dynamic Programming 
    // Time Complexity O(n^2)
    // Space Complexity O(n^2)
    bool dp(const string& s, const string& t) {
        int sn = s.size();
        int tn = t.size();

        vector<vector<int>> dp(sn + 1, vector<int>(tn + 1));

        for (int si = 0; si <= sn; ++si) {
            for (int ti = 0; ti <= tn; ++ti) {
                if (si == 0 || ti == 0) dp[si][ti] = 0;
                else if (s[si - 1] == t[ti - 1]) dp[si][ti] = 1 + dp[si - 1][ti - 1];
                else {
                    dp[si][ti] = max(dp[si - 1][ti], dp[si][ti - 1]);
                }
            }
        }

        return dp[sn][tn] == s.size();
    }
};
