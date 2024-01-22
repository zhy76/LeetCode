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
    int res = 0;
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        int tmp = max(root->val + left, root->val + right);
        res = max(res, root->val + left + right);
        return tmp;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};