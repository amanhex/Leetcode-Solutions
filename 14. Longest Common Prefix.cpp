/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int prefix = strs[0].size();
        int n = strs.size();
        for (int i = 0; i < n; i++){
            int j = 0;
            while (j < strs[i].size() && strs[i][j] == strs[0][j])
                j++;
            prefix = min(prefix, j);
        }
        return strs[0].substr(0, prefix);
    }
};