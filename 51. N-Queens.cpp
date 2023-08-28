/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

Constraints:
1 <= n <= 9
*/

class Solution {
public:
    bool fill(vector<string>& board, int n, int row, int col){
        int i = row, j = col;
        // Checking for left up diagonal
        while (i >= 0 && j >= 0){
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        // Checking for left row
        i = row, j = col;
        while (j >= 0){
            if (board[i][j] == 'Q')
                return false;
            j--;
        }

        // Checking for left down diagonal
        i = row, j = col;
        while (i < n && j >= 0){
            if (board[i][j] == 'Q')
                return false;
                i++;
                j--;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& board, int n, int col){
        if (col == n){
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++){
            if (fill(board, n, row, col)){
                board[row][col] = 'Q';
                solve(ans, board, n, col + 1);
                board[row][col] = '.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(ans, board, n, 0);
        return ans;
    }
};
