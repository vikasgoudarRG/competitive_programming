class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // return stacking(s) == stacking(t); 
        return two_pointers(s, t);
    }   

    // Stack
    // Time Complexity O(n)
    // Space Complexity O(n) 
    string stacking(string s) {
        string ans = "";
        for (char c: s) {
            if (c == '#') {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            }
            else {
                ans.push_back(c);
            }
        }
        return ans;
    }

    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    bool two_pointers(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int skip_s = 0;
        int skip_t = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skip_s++;
                    i--;
                }
                else if (skip_s > 0) {
                    skip_s--;
                    i--;
                }
                else {
                    break;
                }
            }

            while (j >= 0) {
                if (t[j] == '#') {
                    skip_t++;
                    j--;
                }
                else if (skip_t > 0) {
                    skip_t--;
                    j--;
                }
                else {
                    break;
                }
            }
            if ( (i >= 0) && (j >= 0) && (s[i] != t[j]) ) {
                return false;
            }

            if  ((i >= 0) != (j >= 0))  {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
}