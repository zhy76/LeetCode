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
    TreeNode* find(TreeNode* root, int valp, int valq) {
        if(root == NULL) return root;
        if(root->val < valp) {
            return find(root->right, valp, valq);
        } else if(root->val > valq){
            return find(root->left, valp, valq);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int valp = min(p->val, q->val);
        int valq = max(p->val, q->val);
        return find(root, valp, valq); 
    }
};