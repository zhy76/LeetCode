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
    bool isValidBST(TreeNode* root, long left=LONG_MIN,long right=LONG_MAX) {
        if (root==nullptr){
            return true;
        }
        long x=root->val;
        return left<x&&x<right && isValidBST(root->left,left,x) && isValidBST(root->right,x,right);
    }
};