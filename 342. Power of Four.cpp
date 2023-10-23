/*
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:
Input: n = 16
Output: true

Example 2:
Input: n = 5
Output: false

Example 3:
Input: n = 1
Output: true

Constraints:
-231 <= n <= 231 - 1

Follow up: Could you solve it without loops/recursion?
*/

// Using while loop
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;

        while (n % 4 == 0)
            n /= 4;
        return n == 1;
    }
};

// Using Binary Search
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        int low = 0, high = 31;
        while (low < high){
            int mid = low + (high - low) / 2;
            long long power = pow(4, mid);
            if (power == n) return true;
            else if (power > n) high = mid - 1;
            else low = mid + 1;
        }
        return pow(4, low) == n;
    }
};
