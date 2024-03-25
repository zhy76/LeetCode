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
    bool check(TreeNode* a, TreeNode* b) {
        if(a == nullptr && b == nullptr) return true;
        if(a == nullptr || b == nullptr) return false; 
        if(a->val != b->val) return false;
        bool left = check(a->left, b->right);
        bool right = check(a->right, b->left);
        return left && right;
    }
    bool checkSymmetricTree(TreeNode* root) {
        if(root == nullptr) return true;
        return check(root->left, root->right);
    }
};