class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        three_pointers(nums1, m, nums2, n);    
    }

    // Three Pointers
    // Time Complexity O(n + m)
    // Space Complexity O(1)
    void three_pointers(vector<int>& nums_m, int m, vector<int>& nums_n, int n) {
        int read_m = m - 1;
        int read_n = n - 1;
        int write = m + n - 1;

        while (read_m >= 0 && read_n >= 0) {
            if (nums_m[read_m] > nums_n[read_n]) {
                nums_m[write--] = nums_m[read_m--];
            }
            else {
                nums_m[write--] = nums_n[read_n--];
            }
        }

        while (read_n >= 0) {
            nums_m[write--] = nums_n[read_n--];
        }
    }
}