/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

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

// Recursive Approach

class Solution {
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return result;
        inorderTraversal(root -> left);
        result.push_back(root -> val);
        inorderTraversal(root -> right);
        return result;
    }
};

// Iterative Approach (Using Stack)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode*> inorder;
        TreeNode* visited = root;
        while (visited || !inorder.empty()){
            if (visited){
                inorder.push(visited);
                visited = visited -> left;
            }
            else{
                visited = inorder.top();
                inorder.pop();
                result.push_back(visited -> val);
                visited = visited -> right;
            }
        }
        return result;
    }
};