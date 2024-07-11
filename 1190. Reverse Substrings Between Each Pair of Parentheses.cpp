/*
You are given a string s that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets.

Example 1:
Input: s = "(abcd)"
Output: "dcba"

Example 2:
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Example 3:
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

Constraints:
    1 <= s.length <= 2000
    s only contains lower case English characters and parentheses.
    It is guaranteed that all parentheses are balanced.
*/

// Using stack
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ')'){
                string rev = "";
                while (st.top() != '('){
                    rev += st.top();
                    st.pop();
                }
                st.pop();
                for (char c : rev)
                    st.push(c);
            }
            else
                st.push(s[i]);
        }

        string ans = "";
        while (!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

// Using Direction based traversal
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string res = "";
        map<int, int> mp;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int openIndex = st.top();
                st.pop();
                mp[openIndex] = i;
                mp[i] = openIndex;
            }
        }

        int i = 0, direction = 1;
        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = mp[i];
                direction *= -1;
            } else {
                res += s[i];
            }
            i += direction;
        }

        return res;
    }
};
