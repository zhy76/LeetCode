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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> qu;
        qu.push(root);    
        while(!qu.empty()){
            int sz = qu.size();
            vector<int> tmp;
            for(int i=0; i<sz; i++) {
                TreeNode* cur = qu.front();
                tmp.emplace_back(cur->val);
                qu.pop();
                if(cur->left != nullptr) {
                    qu.push(cur->left);
                }
                if(cur->right != nullptr) {
                    qu.push(cur->right);
                }
            }
            ans.emplace_back(tmp);
        }
        for(int i=1; i<ans.size(); i+=2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};