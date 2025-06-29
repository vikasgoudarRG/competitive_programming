// https://leetcode.com/problems/find-smallest-letter-greater-than-target/editorial/?envType=study-plan-v2&envId=binary-search

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size();

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (letters[middle] <= target) {
                left = middle + 1;
            }
            else {
                right = middle;
            }
        }
        return left == letters.size() ? letters[0] : letters[left];
    }
};
