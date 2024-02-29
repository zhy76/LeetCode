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
    bool check(TreeNode* root, TreeNode* B) {
        if(B == NULL) return true;
        if(root == NULL || root->val != B->val) {
            return false;
        }
        bool left = check(root->left, B->left);
        bool right = check(root->right, B->right);
        return left && right;
    }
    
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A != NULL && B!=NULL) && (check(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
};