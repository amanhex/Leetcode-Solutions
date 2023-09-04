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

// Using Backtracking with memoization
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

// Using dp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (const string& word : wordDict) {
                int len = word.length();
                if (i >= len && dp[i - len] && s.substr(i - len, len) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }      
        return dp[n];
    }
};
