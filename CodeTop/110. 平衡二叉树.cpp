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
    int getDepth(TreeNode* node) {
        if(node == nullptr) return 0;
        int left = getDepth(node->left);
        int right = getDepth(node->right);
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};