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
    TreeNode* dfs(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* left = dfs(root->left);
        TreeNode* right = dfs(root->right);
        root->right = left;
        root->left = nullptr;
        TreeNode* p = root;
        while(p->right != nullptr) {
            p = p->right;
        }
        p->right = right;
        return root;
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};