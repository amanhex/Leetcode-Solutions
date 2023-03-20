/*
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.
*/

// Brute Force Approach (Gives TLE)
class Solution {
public:
    bool isPalindrome(string s){
        int start = 0, end = s.size() - 1;
        while (start < end){
            if (s[start] == s[end]){
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0)
            return "";
        else if (len == 1)
            return s;
        string res = "";
        for (int i = 0; i < len; i++){
            for (int j = 0; j <= len - i; j++){
                if (isPalindrome(s.substr(i, j))){
                    if (res.size() < s.substr(i, j).size())
                        res = s.substr(i, j);
                }
            }
        }
        return res;
    }
};

// Dynamic Programming Approach
