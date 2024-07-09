/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]

Constraints:
    1 <= inorder.length <= 3000
    postorder.length == inorder.length
    -3000 <= inorder[i], postorder[i] <= 3000
    inorder and postorder consist of unique values.
    Each value of postorder also appears in inorder.
    inorder is guaranteed to be the inorder traversal of the tree.
    postorder is guaranteed to be the postorder traversal of the tree.
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
class Solution {
private:
    TreeNode* construct(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>& inMap){
        if (inStart > inEnd || postStart > postEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root -> val];
        int numsLeft = inRoot - inStart;

        root -> left = construct(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);
        root -> right = construct(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        TreeNode* root = construct(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
        return root;
    }
};
