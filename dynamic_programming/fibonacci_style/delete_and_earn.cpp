// https://leetcode.com/problems/delete-and-earn/submissions/1646210028/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
            // best of both sorting method and bottom-up method
        // bottom up is O(n + n*logn) and sorting is O(n+k)
        // so depends on which is bigger, k or n*logn

        map<int, int> freq;
        int max_number = nums[0];
        for (int i : nums) {
            max_number = max(i, max_number);
            freq[i]++;
        }

        if (max_number > freq.size() * log(freq.size()) / log(2)) {
            vector<int> keys;
            for (const auto& i : freq) {
                keys.push_back(i.first);
            }

            sort(keys.begin(), keys.end());
            int two_back = 0;
            int one_back = freq[keys[0]]*keys[0];
            for (int i = 1; i < keys.size(); ++i) {
                            cout << two_back << " " << one_back << " " << keys[i] << endl;

                if (keys[i] == keys[i-1] + 1) {
                    int temp = one_back;
                    one_back = max(one_back, two_back + keys[i]*freq[keys[i]]);
                    two_back = temp;
                }
                else {
                    int temp = one_back;
                    one_back = one_back + keys[i]*freq[keys[i]];
                    two_back = temp;
                }
            }
            return one_back;
        }
        else {
            int two_back = 0;
            int one_back = freq[1];
            for (int i = 2; i <= max_number; ++i) {
                int temp = one_back;
                one_back = max(one_back, two_back + i*freq[i]);
                two_back = temp;
            }
            return one_back;   
        }
        
        /*
            // sorting and looping
        // better if array is like [0,2,3,9999] 
        // bottom-up approach loops from 0 till max number
        // this method loops over array
        // so this method is better if max_number >>> total elements

        map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        vector<int> keys;
        for (const auto& i : freq) {
            keys.push_back(i.first);
        }

        sort(keys.begin(), keys.end());
        int two_back = 0;
        int one_back = freq[keys[0]]*keys[0];
        for (int i = 1; i < keys.size(); ++i) {
                        cout << two_back << " " << one_back << " " << keys[i] << endl;

            if (keys[i] == keys[i-1] + 1) {
                int temp = one_back;
                one_back = max(one_back, two_back + keys[i]*freq[keys[i]]);
                two_back = temp;
            }
            else {
                int temp = one_back;
                one_back = one_back + keys[i]*freq[keys[i]];
                two_back = temp;
            }
        }
        return one_back;
        */

        /*
            // space optimized bottom-up
        // read bottom-up approach to understand
        map<int, int> freq;
        int max_number = 0;
        for (int i : nums) { 
            freq[i]++;
            max_number = max(max_number, i);
        }
        int two_back = 0;
        int one_back = freq[1];
        for (int i = 2; i <= max_number; ++i) {
            int temp = one_back;
            one_back = max(one_back, two_back + i*freq[i]);
            two_back = temp;
        }
        return one_back;
        */

        /*
            // top-down approach
        map<int, int> freq;
        int max_number = nums[0];
        for (int i : nums) {
            freq[i]++;
            max_number = max(max_number, i);
        }
        map<int, int> dp;
        return recur(max_number, freq, dp);
        */

        /*
            // bottom-up approach
        map<int, int> freq;
        int max_number = nums[0];
        for (int i : nums) {
            max_number = max(max_number, i);
            freq[i]++;
        }

        vector<int> dp(max_number + 1, 0);
        dp[1] = freq[1];
        for (int i = 2; i <= max_number; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + i*freq[i]);
        }
        return dp[max_number];
        */
    }

    /*
    int recur(int i, map<int, int>& freq, map<int, int>& dp) {
        if (i == 0) return 0;
        if (i == 1) return freq[1];

        if (dp.count(i)) return dp[i];

        dp[i] = max(recur(i-1, freq, dp), recur(i-2, freq, dp) + i*freq[i]);
        return dp[i];
    }
    */
};
