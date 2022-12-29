/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100

Follow up: Could you solve it both recursively and iteratively?
*/


// Recursive Solution (Use Queue for iterative solution)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root1, TreeNode* root2){
        if (!root1 && !root2)
            return true;
        else if (!root1 || !root2)
            return false;
        else if (root1 -> val != root2 -> val)
            return false;
        return isSymmetric(root1 -> left, root2 -> right) && isSymmetric(root1 -> right, root2 -> left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSymmetric(root -> left, root -> right);
    }
};