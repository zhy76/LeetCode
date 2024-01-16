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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int prel, int prer,int inl, int inr) {
        if(prel > prer || inl > inr) return nullptr;
        int k = 0;
        for(int i=inl; i<=inr; i++) {
            if(inorder[i] == preorder[prel]) {
                k = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(preorder[prel]);
        root->left = build(preorder, inorder, prel+1, k-inl+prel, inl, k-1);
        root->right = build(preorder, inorder, k-inl+prel+1, prer, k+1,inr);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};