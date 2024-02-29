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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        res = max(res, left + right + 1);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        maxDepth(root);
        return res - 1;
    }
};