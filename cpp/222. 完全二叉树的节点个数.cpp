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
    int countNodes(TreeNode* root) {
        int h1=0, h2=0;
        TreeNode* l = root, *r = root;
        while(l != nullptr) {
            l = l->left;
            h1++;
        }
        while(r !=nullptr) {
            r = r->right;
            h2++;
        }
        if(h1 == h2) {
            return pow(2, h1) - 1;
        }
        return 1+countNodes(root->left) + countNodes(root->right);
    }
};