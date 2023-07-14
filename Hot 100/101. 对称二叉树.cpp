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
    bool dfs(TreeNode* l,TreeNode* r){
        if (!l && !r) {
            return true;
        }
        if (!l || !r) {
            return false;
        }
        return l->val == r->val && dfs(l->right,r->left) && dfs(l->left,r->right);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root,root);
    }
};