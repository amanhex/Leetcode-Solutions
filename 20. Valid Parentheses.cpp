/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

class Solution {
public:
    bool isValid(string s) {
        int s_len = s.length();
        if (s_len % 2 != 0) return false;
        
        stack<char> st;
        for (int i = 0; i < s_len; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                } else if (st.top() =='(' && s[i] != ')' || st.top() =='{' && s[i] != '}'
                   || (st.top() =='[' && s[i] != ']')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};