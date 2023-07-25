/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

// Brute Force Approach

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == target)
                    return true;
        }
        return false;
    }
};

// Better Approach 1

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++){
                int start = 0, end = matrix[i].size() - 1;
                while (start <= end){
                    int mid = start + (end - start) / 2;
                    if (matrix[i][mid] == target)
                        return true;
                    else if (matrix[i][mid] > target)
                        end = mid - 1;
                    else
                        start = mid + 1;
                }
        }
        return false;
    }
};

// Better Approach 2 (More Better than previous solutions)
// Two pointer approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = m - 1;
        while (left < n && right >= 0){
            if (matrix[left][right] == target)
                return true;
            else if (matrix[left][right] > target)
                right--;
            else
                left++;
        }
        return false;
    }
};