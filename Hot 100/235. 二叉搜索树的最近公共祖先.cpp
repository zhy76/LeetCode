/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* find(TreeNode* root, int v1, int v2) {
        if(root == NULL) {
            return NULL;
        }
        if(root->val > v2) {
            return find(root->left, v1, v2);
        }
        if(root->val < v1) {
            return find(root->right, v1, v2);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v1 = min(p->val, q->val);
        int v2 = max(p->val, q->val);
        return find(root, v1, v2);
    }
};