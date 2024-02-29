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
    int ans=0;
    void dfs(TreeNode* root,int depth){
        if(root == nullptr){
            ans=max(ans,depth);
            return;
        }
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};