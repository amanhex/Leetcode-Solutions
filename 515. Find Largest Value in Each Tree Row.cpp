/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]

Constraints:
The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1
*/

// Using BFS
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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;
        while (!q.empty()){
            int levelMax = INT_MIN;
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                levelMax = max(levelMax, node -> val);
                if (node -> left)
                    q.push(node -> left);
                if (node -> right)
                    q.push(node -> right);
            }
            ans.push_back(levelMax);
        }
        return ans;
    }
};

// Using DFS
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
    void dfs(TreeNode* root, vector<int>& ans, int level){
        if (!root) return;
        if (level >= ans.size()) ans.push_back(INT_MIN);

        ans[level] = max(ans[level], root -> val);
        dfs(root -> left, ans, level + 1);
        dfs(root -> right, ans, level + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }
};
