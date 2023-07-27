/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:
1 <= m, n <= 100
*/

// DP Solution
class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp){
        if (i > m - 1 || j > n - 1)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans1 = countPaths(i + 1, j, m, n, dp);
        int ans2 = countPaths(i, j + 1, m, n, dp);
        dp[i][j] = ans1 + ans2;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(0, 0, m, n, dp);
    }
};

// Combination Solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        int minn = min(m, n) - 1;
        int up = m + n - 2;
        double smallAns1 = 1, smallAns2 = 1;
        for (int i = 1; i <= minn; i++){
            smallAns1 *= up;
            smallAns2 *= i;
            up--;
        }
        return (int)(smallAns1 / smallAns2);
    }
};