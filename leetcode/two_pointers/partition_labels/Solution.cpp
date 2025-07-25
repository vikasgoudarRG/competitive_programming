class Solution {
public:
    vector<int> partitionLabels(string s) {

        return two_pointers(s);
    }

    // Pointers
    // Time Complexity O(n)
    // Space Complexity O(n)
    vector<int> two_pointers(string s) {
        int n = s.length();

        unordered_map<char, int> last_occurence;
        for (int i = 0; i < n; ++i) {
            last_occurence[s[i]] = i;
        }

        vector<int> ans;
        int low = 0;
        int high;
        int end = 0;

        for (high = 0; high < n; ++high) {
            end = max(end, last_occurence[s[high]]);
            if (high == end) {
                ans.push_back(high - low + 1);
                low = high + 1;
            }
        }

        return ans;
    }
}