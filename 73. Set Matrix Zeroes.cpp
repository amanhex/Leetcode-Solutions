/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

Follow up:
A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

// Time Complexity of this solution = O((N*M)*(N + M)) + O(N*M) {M = number of rows & N = number of columns}
// Space Complexity of this solution = O(1)

class Solution {
public:
    void setRowZero(vector<vector<int>>& matrix, int row){
        for (int i = 0; i < matrix[row].size(); i++)
            if (matrix[row][i] != 0)
                matrix[row][i] = INT_MIN + 8;
    }

    void setColZero(vector<vector<int>>& matrix, int col){
        for (int i = 0; i < matrix.size(); i++){
            if (matrix[i][col] != 0)
                matrix[i][col] = INT_MIN + 8;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == 0){
                    setRowZero(matrix, i);
                    setColZero(matrix, j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == INT_MIN + 8)
                    matrix[i][j] = 0;
            }
        }
    }
};

// Time Complexity of this solution = O(2*(N*M))
// Space Complexity of this solution = O(M) + O(N)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row(matrix.size());
        vector<int> col(matrix[0].size());
        row = {0};
        col = {0};
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

// Time Complexity of this solution = O(2*(N*M))
// Space Complexity of this solution = O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};