/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Constraints:
The number of the nodes in the tree is in the range [0, 100].
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return result;
        postorderTraversal(root -> left);
        postorderTraversal(root -> right);
        result.push_back(root -> val);
        return result;
    }
};

// Iterative Approach (Using Two Stacks)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        stack<TreeNode*> s;
        s.push(root);
        stack<int> out;
        while (!s.empty())
        {
            TreeNode* curr = s.top();
            s.pop();
            out.push(curr -> val);
            if (curr -> left)
                s.push(curr -> left);
            if (curr -> right)
                s.push(curr -> right);
        }
        while (!out.empty())
        {
            result.push_back(out.top());
            out.pop();
        }
        return result;
    }
};