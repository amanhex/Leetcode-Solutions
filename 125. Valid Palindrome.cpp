/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        if (left == right)
            return true;
        while (left < right){
            if ((isalpha(s[left]) || isdigit(s[left])) && (isalpha(s[right]) || isdigit(s[right]))){
                if (isalpha(s[left]) && isdigit(s[right]) || isalpha(s[right]) && isdigit(s[left]))
                    return false;
                else if (s[left] - s[right] == 0 || abs(s[left] - s[right]) == 32){
                    left++;
                    right--;
                }
                else
                    return false;
            }
            else if (!isalpha(s[left]) && !isdigit(s[left]))
                left++;
            else
                right--;
        }
        return true;
    }
};