/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    string getSorted(const string& s){
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        return sorted;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs)
            groups[getSorted(s)].push_back(s);
        for (const auto& entry : groups)
            ans.push_back(entry.second);
        return ans;
    }
};
