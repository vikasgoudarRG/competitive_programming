class Solution {
public:
    int maxArea(vector<int>& height) {
        return two_pointers(height);
    }
    
    // Two Pointers
    // Time Complexity O(n)
    // Space Complexity O(1)
    int two_pointers(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int ans = 0;
        while (left < right) {
            int width = right - left;
            ans = max(ans, width * min(height[right], height[left]));

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return ans;
    }
}