/*
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true

Example 2:
Input: word = "FlaG"
Output: false

Constraints:
1 <= word.length <= 100
word consists of lowercase and uppercase English letters.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        int loc;
        for(int i = 0; i < word.length(); i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                count++;
                loc = i;
            }
        }
        if(count == word.length() || count == 0 || (count == 1 && loc == 0))
            return true;
        return false;
    }
};   