/*
You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

Example 1:
Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

Example 2:
Input: grid = [[0]]
Output: 1

Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 20
    grid[i][j] is either 0 or 1.
*/

class Solution {
public:
    void flipRow(vector<vector<int>>& grid, int r, int cols){
        for (int i = 0; i < cols; i++){
            grid[r][i] = !grid[r][i];
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        // Flip row
        for (int r = 0; r < rows; r++){
            if (grid[r][0] == 0)
                flipRow(grid, r, cols);
        }

        int res = 0;
        for (int c = 0; c < cols; c++) {
            int colSum = 0;
            for (int r = 0; r < rows; r++) {
                colSum += grid[r][c];
            }
            int contribution = max(colSum, rows - colSum);
            res += contribution * (1 << (cols - c - 1));
        }
        return res;
    }
};
