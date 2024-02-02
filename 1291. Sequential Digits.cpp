/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:
Input: low = 100, high = 300
Output: [123,234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

Constraints:
10 <= low <= high <= 10^9
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        for (int i = 1; i <= 9; i++){
            int num = i;
            int nextDigit = i + 1;
            while (num <= high && nextDigit <= 9){
                num = num * 10 + nextDigit;
                if (low <= num && num <= high) ans.push_back(num);
                else if (num > high) break;
                ++nextDigit;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
