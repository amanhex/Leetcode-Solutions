/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/

class Solution {
public:
    void reverseWords(string &s, int start, int end){
        for (int i = start, j = end - 1; i < start + (end - start) / 2; i++, j--){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
    string reverseWords(string s) {
        int start = 0, end = 0;
        while (end < s.size()){
            while (s[end] != ' ' && end < s.size())
                end++;
            reverseWords(s, start, end);
            start = end + 1;
            end++;
        }
        return s;
    }
};