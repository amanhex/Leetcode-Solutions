/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x. 

Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false

Constraints:
-231 <= n <= 231 - 1

Follow up: Could you solve it without loops/recursion?
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        
        int left = 0, right = 30;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int powerOfTwo = 1 << mid;
            if (powerOfTwo == n)
                return true;
            else if (powerOfTwo < n)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
