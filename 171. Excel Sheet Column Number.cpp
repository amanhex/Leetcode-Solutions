/*
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

Example 1:
Input: columnTitle = "A"
Output: 1

Example 2:
Input: columnTitle = "AB"
Output: 28

Example 3:
Input: columnTitle = "ZY"
Output: 701

Constraints:
1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].
*/

// Using HashMap
class Solution {
public:
    int titleToNumber(string columnTitle) {
        unordered_map<char, int> alphabets;
        int i = 65;
        int j = 1;
        while (i < 96){
            alphabets[(char(i))] = j;
            i++;
            j++;
        }
        int columnNumber = 0;
        for (int i = columnTitle.size() - 1; i >= 0; i--){
            columnNumber += pow(26, i) * alphabets[columnTitle[columnTitle.size() - i - 1]];
        }
        return columnNumber;
    }
};

// Optimized Solution

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i = 0; i < columnTitle.size(); i++){
            int temp = (columnTitle[i] - 65) + 1;
            ans = ans * 26 + temp;
        }
        return ans;
    }
};