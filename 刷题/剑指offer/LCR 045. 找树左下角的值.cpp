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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* res = nullptr;
        while(!qu.empty()) {
            int sz = qu.size();
            for(int i = 0; i < sz; i++) {
                auto cur = qu.front();
                qu.pop();
                if(cur->right) qu.push(cur->right);
                if(cur->left) qu.push(cur->left);
                res = cur;
            }
        }
        return res->val;
    }
};