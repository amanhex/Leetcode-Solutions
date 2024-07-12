/*
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

    Remove substring "ab" and gain x points.
        For example, when removing "ab" from "cabxbae" it becomes "cxbae".
    Remove substring "ba" and gain y points.
        For example, when removing "ba" from "cabxbae" it becomes "cabxe".

Return the maximum points you can gain after applying the above operations on s.

Example 1:
Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.

Example 2:
Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20

Constraints:
    1 <= s.length <= 105
    1 <= x, y <= 104
    s consists of lowercase English letters.
*/

class Solution {
public:
    int removePairs(string& s, string pair, int score) {
        int res = 0;
        stack<char> st;
        for (char c : s) {
            if (c == pair[1] && !st.empty() && st.top() == pair[0]) {
                st.pop();
                res += score;
            }
            else
                st.push(c);
        }

        string newS(st.size(), ' ');
        for (int i = st.size() - 1; i >= 0; --i) {
            newS[i] = st.top();
            st.pop();
        }
        s = newS;
        return res;
    }

    int maximumGain(string s, int x, int y) {
        int res = 0;
        if (x > y) {
            res += removePairs(s, "ab", x);
            res += removePairs(s, "ba", y);
        } else {
            res += removePairs(s, "ba", y);
            res += removePairs(s, "ab", x);
        }
        return res;
    }
};

