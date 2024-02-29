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
    void preorder(TreeNode* root, vector<TreeNode*> &l){
        if (root !=NULL){
            l.push_back(root);
            preorder(root->left,l);
            preorder(root->right,l);
        }
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        preorder(root,l);
        int n=l.size();
        for(int i=1;i<n;i++){
            TreeNode *prev = l.at(i-1), *curr=l.at(i);
            prev->left=nullptr;
            prev->right=curr;
        }
    }
};