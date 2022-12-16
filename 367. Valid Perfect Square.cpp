/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt.

Example 1:
Input: num = 16
Output: true

Example 2:
Input: num = 14
Output: false

Constraints:
1 <= num <= 2^31 - 1
*/

class Solution {
public:
    bool isPerfectSquare(int num, int low, int high){
        if (low > high)
            return false;
        long mid = low + (high - low) / 2;
        if (mid * mid == num)
            return mid;
        else if (mid * mid > num)
            return isPerfectSquare(num, low, mid - 1);
        else
            return isPerfectSquare(num, mid + 1, high);
    }

    bool isPerfectSquare(int num) {
        return isPerfectSquare(num, 0, num);
    }
};