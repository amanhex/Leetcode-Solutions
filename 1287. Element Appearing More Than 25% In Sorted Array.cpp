/*
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

Example 1:
Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6

Example 2:
Input: arr = [1,1]
Output: 1

Constraints:
1 <= arr.length <= 104
0 <= arr[i] <= 105
*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size();
        int min = size / 4;
        int freq = 1, ans = arr[0];
        for (int i = 1; i < size; i++){
            if (arr[i - 1] == arr[i])
                ++freq > min ? ans = arr[i] : ans;
            else
                freq = 1;
        }
        return ans;
    }
};
