/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

// if a string contains permutation of other string then it must contain the same frequency of 
// characters in some of part of it. Using sliding window to confirm that part.

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) 
            return false;
        vector<int> frequencyS1(26, 0);
        for (auto c : s1)
            frequencyS1[c - 'a']++; // storing frequency of characters of s1
        vector<int> frequencyS2(26, 0);
        int i = 0, j = 0;
        while (j < s2.size()){
            frequencyS2[s2[j] - 'a']++; // storing frequency of characters of s2
            if (j - i + 1 == s1.size()) // checking if size of window is equal to the length of s1
                if (frequencyS1 == frequencyS2) // checking if frequency of characters in window and frequency of characters of s1 are same
                    return true;
            if (j - i + 1 < s1.size()) // if size is small increasing the range of window
                j++;
            else{
                frequencyS2[s2[i] - 'a']--; // decreasing size of window when size of window is greater than the length of s1
                i++;
                j++;
            }
        }
        return false;
    }
};
