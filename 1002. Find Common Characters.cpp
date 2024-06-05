/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: words = ["cool","lock","cook"]
Output: ["c","o"]

Constraints:
    1 <= words.length <= 100
    1 <= words[i].length <= 100
    words[i] consists of lowercase English letters.
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt = count(words[0]);
        for (int i = 1; i < words.size(); i++){
            cnt = intersection(cnt, count(words[i]));
        }

        vector<string> result;
        for (int i = 0; i < 26; i++){
            while (cnt[i] > 0){
                result.push_back(string(1, 'a' + i));
                cnt[i]--;
            }
        }

        return result;
    }

    private:
        vector<int> count(const string& str){
            vector<int> freq(26, 0);
            for (char c : str){
                freq[c - 'a']++;
            }
            return freq;
        }

        vector<int> intersection(const vector<int>& a, const vector<int>& b){
            vector<int> t(26, 0);
            for (int i = 0; i < 26; i++){
                t[i] = min(a[i], b[i]);
            }
            return t;
        }
};
