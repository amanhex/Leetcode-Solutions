/*
 Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

Constraints:
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
 */

class Solution {
public:
    bool wordBreakHelper(string& s, int start, vector<string>& wordDict, unordered_map<string, bool>& memo){
        if (start == s.length())
            return true;
        
        if (memo.find(s.substr(start)) != memo.end())
            return memo[s.substr(start)];
        
        for (const string& word : wordDict){
            if (s.substr(start, word.length()) == word){
                if (wordBreakHelper(s, start + word.length(), wordDict, memo)) {
                    memo[s.substr(start)] = true;
                    return true;
                }
            }
        }
        memo[s.substr(start)] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> memo;
        return wordBreakHelper(s, 0, wordDict, memo);
    }
};
