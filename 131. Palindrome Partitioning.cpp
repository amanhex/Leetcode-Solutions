/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

Constraints:
1 <= s.length <= 16
s contains only lowercase English letters.
*/

class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while (start < end){
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void genSubstring(string s, vector<vector<string>>& res, vector<string>& current, int index){
        if (index == s.size()){
            res.push_back(current);
            return;
        }
        for (int i = index; i < s.size(); i++){
            if (isPalindrome(s, index, i)){
                current.push_back(s.substr(index, i - index + 1));
                genSubstring(s, res, current, i + 1);
                current.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        genSubstring(s, res, current, 0);
        return res;
    }
};
