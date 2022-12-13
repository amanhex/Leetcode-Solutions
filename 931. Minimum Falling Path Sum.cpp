/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    int getMinUntil(int i, int j, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if (j < 0 || j >= m)
            return 1e9;
        if (i == 0)
            return matrix[0][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = matrix[i][j] + getMinUntil(i - 1, j, m, matrix, dp);
        int leftDiagonal = matrix[i][j] + getMinUntil(i - 1, j - 1, m, matrix, dp);
        int rightDiagonal = matrix[i][j] + getMinUntil(i - 1, j + 1, m, matrix, dp);
        return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mini = INT_MAX;
        for (int j = 0; j < n; j++){
            int ans = getMinUntil(n - 1, j, n, matrix, dp);
            mini = min(mini, ans);
        }
        return mini;
    }
};