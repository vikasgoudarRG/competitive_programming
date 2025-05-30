// https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
            // bit manipulation
        int a = 0;
        for (int i : nums) {
            a ^= i;
        }
        return a;

        /*
            // Hash Table O(n)
        unordered_map<int, int> hash;
        for (int i : nums) {
            hash[i]++;
        }
        for (auto& pair : hash) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return 0;
        */

        /*
            // List operations O(n^2)
        vector<int> no_duplicates;
        for (int i : nums) {
            if (find(no_duplicates.begin(), no_duplicates.end(), i) == no_duplicates.end()) {
                no_duplicates.push_back(i);
            }
            else {
                no_duplicates.erase(remove(no_duplicates.begin(), no_duplicates.end(), i), no_duplicates.end());
            }
        }
        return no_duplicates[0];
        */
    }
};
