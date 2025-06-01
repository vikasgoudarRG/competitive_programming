// https://leetcode.com/problems/longest-palindromic-substring/submissions/1650493878/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    string longestPalindrome(string s) {
            // Manacher's Algorithm O(n)
        string s_prime = "#";
        for (char c : s) {
            s_prime += c;
            s_prime += "#";
        }
        
        int n = s_prime.size();
        vector<int> dp(n, 0);
        int r = 0;
        int c = 0;

        for (int i = 0; i < n; ++i) {
            if (i < r) {
                // int mirror = c - (i-c);
                int mirror = 2*c - i;
                dp[i] = min(dp[mirror], r - i);
            }
            while (i + 1 + dp[i] < n && i - 1 - dp[i] >= 0 && s_prime[i + 1 + dp[i]] == s_prime[i - 1 - dp[i]]) {
                ++dp[i];
            }
            if (i + dp[i] > r) {
                c = i;
                r = i + dp[i];
            }
        }

        int max_ = 0;
        c = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > max_) {
                max_ = dp[i];
                c = i;
            }
        }
        int start = (c - max_) / 2;
        return s.substr(start, max_);


        /*
            // expand from center O(n^2) 
        // more memory friendly than dp
        // in practicality faster than dp, since dp has to populate the whole dp array
        // where as expand from center can cut off early
        int start = 0;
        int end = 0;

        for (int center = 0; center < s.size(); ++center) {
            vector<int> temp;
            // odd
            temp = expand(center, center, s);
            if (temp[1] - temp[0] > end - start) {
                start = temp[0];
                end = temp[1];
            }

            // even
            temp = expand(center, center + 1, s);
            if (temp[1] - temp[0] > end - start) {
                start = temp[0];
                end = temp[1];
            }
        }
        return s.substr(start, end - start + 1);
        */

        /*
            // dp O(n^2)
        vector<int> ans = {0, 1};
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                ans = {i, 2};
            }
        }

        for (int len = 3; len <= s.size(); ++len) {
            for (int start = 0; start <= s.size() - len; ++start) {
                if (s[start] == s[start+len-1]) {
                    if (dp[start+1][start+len-2] == true) {
                        dp[start][start+len-1] = true;
                        ans = {start, len};
                    }
                }
            }
        }
        return s.substr(ans[0], ans[1]);
        */

        /*
            // hard-coded O(n^3)
        // works because in practicality the O(n^3) cuts off early because we go from larger
        // to smaller substrings
        for (int length = s.size(); length > 0; --length) {
            for (int start = 0; start <= s.size() - length; ++start) {
                if (isSubstring(s, start, length)) {
                    return s.substr(start, length);
                }
            }
        }
        return "";
        */
    }
    /*
    vector<int> expand(int l, int r, const string& str) {
        while (l >= 0 && r < str.size()) {
            if (str[l] != str[r]) {
                break;
            }
            else {
                --l;
                ++r;
            }
        }
        ++l;
        --r;
        return {l, r};
    }
    */

    /*
    bool isSubstring(const string& str, int start, int len) {
        int left = start;
        int right = start + len - 1;

        while (left < right) {
            if (str[left] == str[right]) {
                ++left;
                --right;
            }
            else {
                return false;
            }
        }
        return true;
    }
    */

};
