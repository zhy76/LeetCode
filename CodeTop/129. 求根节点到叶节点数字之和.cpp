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
    void sum(TreeNode* root, int track) {
        if(root == nullptr) return;
        track = track * 10 + root->val;
        if(root ->left == nullptr && root->right == nullptr) {
            // cout<<track<<endl;
            res += track;
            return;
        }
        sum(root->left, track);
        sum(root->right, track);
    }
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        sum(root, 0);
        return res;
    }
};