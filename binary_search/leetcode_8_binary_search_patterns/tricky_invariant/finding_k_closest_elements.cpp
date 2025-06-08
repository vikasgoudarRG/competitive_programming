// https://leetcode.com/problems/find-k-closest-elements/submissions/1657400541/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            // binary search
        int l = 0;
        int r = arr.size() - k;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (x - arr[m] > arr[m + k] - x){
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);

        /*
            // binary search

        if (k >= arr.size()) {
            return arr;
        }

        int l = 0;
        int r = arr.size();

        while (l < r) {
            int m = l + (r - l) / 2;
            if (arr[m] >= x) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        r = l--;

        while (r - l - 1 < k) {
            if (l == -1) {
                ++r;
            }
            else if (r == arr.size()) {
                --l;
            }
            else {
                if ( abs(arr[r] - x) < abs(arr[l] - x) ) {
                    ++r;
                }
                else {
                    --l;
                }
            }
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);

        /*
            // brute force O(N*logN + K*logK)

        sort(arr.begin(), arr.end(), [x](const int& a, const int& b) {
            if ( abs(x - a) == abs(x - b) ) {
                return a < b;
            } 
            return ( abs(x - a) < abs(x - b) );
        });

        sort(arr.begin(), arr.begin() + k);

        return vector<int>(arr.begin(), arr.begin() + k);
        */

    }
};
