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
    vector<vector<int>> decorateRecord(TreeNode* root) {
        if(root == nullptr) return vector<vector<int>>();
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> res;
        bool flag = false;
        while(!qu.empty()) {
            int sz = qu.size();
            vector<int> tmp;
            for(int i = 0; i < sz; i++) {
                auto cur = qu.front();
                qu.pop();
                tmp.push_back(cur->val);
                if(cur->left) qu.push(cur->left);
                if(cur->right) qu.push(cur->right);
            }
            if(flag) {
                reverse(tmp.begin(), tmp.end());
            }
            res.push_back(tmp);
            flag = !flag;
        }
        return res;
    }
};