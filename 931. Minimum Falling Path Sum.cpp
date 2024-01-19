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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1 || n == 1) return matrix[0][0];
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        int ans = INT_MAX;

        for (int i = 0; i < m; i++){
            ans = min(ans, minFallingPathSum(matrix, 0, i, dp));
        }

        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp){
        int m = matrix.size();
        int n = matrix[0].size();

        if (dp[row][col] != INT_MAX) return dp[row][col];

        if (row == m - 1)
            return dp[row][col] = matrix[row][col];

        int left = INT_MAX, right = INT_MAX;

        if (col > 0)
            left = minFallingPathSum(matrix, row + 1, col - 1, dp);
        int straight = minFallingPathSum(matrix, row + 1, col, dp);
        if (col < n - 1)
            right = minFallingPathSum(matrix, row + 1, col + 1, dp);
        
        dp[row][col] = min(left, min(straight, right)) + matrix[row][col];
        return dp[row][col];
    }
};
