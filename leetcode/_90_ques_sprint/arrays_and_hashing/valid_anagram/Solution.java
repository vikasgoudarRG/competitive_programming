package _90_ques_sprint.arrays_and_hashing.valid_anagram;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isAnagram(String s, String t) {
        // return sorting(s, t);
        return hashing(s, t);
    }

    // Sorting
    // Time Complexity O(n * logn)
    // Space Complexity O(n)
    public boolean sorting(String s, String t) {
        if (s.length() != t.length()) return false;
        char[] str1 = s.toCharArray();
        char[] str2 = t.toCharArray();

        Arrays.sort(str1);
        Arrays.sort(str2);

        return Arrays.equals(str1, str2);        
    }

    // HashMap
    // Time Complexity O(n)
    // Space Complexity O(n)
    public boolean hashing(String s, String t) {
        if (s.length() != t.length()) return false;

        Map<Character, Integer> count = new HashMap<>();
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            count.put(ch, count.getOrDefault(ch, 0) + 1);
        } 
        
        for (int i = 0; i < t.length(); ++i) {
            char ch = t.charAt(i);
            if (!count.containsKey(ch)) return false;

            count.put(ch, count.get(ch) - 1);

            if (count.get(ch) == 0) {
                count.remove(ch);
            }
        }

        return count.isEmpty();
    }
}