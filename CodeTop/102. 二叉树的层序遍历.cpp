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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int> > res;
        if(root == nullptr) return res;
        qu.push(root);
        while(!qu.empty()) {
            int sz = qu.size();
            vector<int> tmp;
            for(int i=0; i<sz; i++) {
                TreeNode* cur = qu.front();
                qu.pop();
                tmp.push_back(cur->val);
                if(cur->left != nullptr) qu.push(cur->left);
                if(cur->right != nullptr) qu.push(cur->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};