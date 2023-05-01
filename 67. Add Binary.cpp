/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string res = "";
        while (i > -1 && j > -1){
            if (a[i] == '1' && b[j] == '1'){
                if (carry)
                    res = "1" + res;
                else{
                    res = "0" + res;
                    carry = 1;
                }
            }
            else if (a[i] == '1' || b[j] == '1'){
                if (carry){
                    res = "0" + res;
                    carry = 1;
                }
                else
                    res = "1" + res;
            }
            else{
                if (carry){
                    res = "1" + res;
                    carry = 0;
                }
                else
                    res = "0" + res;
            }
            i--;
            j--;
        }
        if (i > -1){
            while (i > -1){
                if (a[i] == '1'){
                    if (carry){
                        res = "0" + res;
                        carry = 1;
                    }
                    else
                        res = "1" + res;
                }
                else{
                    if (carry){
                        res = "1" + res;
                        carry = 0;
                    }
                    else
                        res = "0" + res;
                }
                i--;
            }
        }
        if (j > -1){
            while (j > -1){
                if (b[j] == '1'){
                    if (carry){
                        res = "0" + res;
                        carry = 1;
                    }
                    else
                        res = "1" + res;
                }
                else{
                    if (carry){
                        res = "1" + res;
                        carry = 0;
                    }
                    else
                        res = "0" + res;
                }
                j--;
            }
        }
        if (carry)
            res = "1" + res;
        return res;
    }
};