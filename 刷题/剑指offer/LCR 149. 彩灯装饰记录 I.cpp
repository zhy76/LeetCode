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
    vector<int> decorateRecord(TreeNode* root) {
        if(root == nullptr) return vector<int>();
        vector<int> res;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()) {
            int sz = qu.size();
            for(int i = 0; i < sz; i++) {
                auto cur = qu.front();
                qu.pop();
                res.push_back(cur->val);
                if(cur->left != nullptr) qu.push(cur->left);
                if(cur->right != nullptr) qu.push(cur->right);
            }
        }
        return res;
    }
};