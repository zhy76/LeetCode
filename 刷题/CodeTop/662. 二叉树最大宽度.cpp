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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, unsigned long long>> qu;
        qu.push({root, 1});
        unsigned long long res = 0;
        while(!qu.empty()) {
            int sz = qu.size();
            unsigned long long start = qu.front().second;
            unsigned long long end = 0;
            for(int i = 0; i < sz; i++) {
                auto cur = qu.front();
                end = cur.second;
                qu.pop();
                if(cur.first->left != nullptr) qu.push({cur.first->left, cur.second * 2});
                if(cur.first->right != nullptr) qu.push({cur.first->right, cur.second * 2 + 1});
                
            }   
            res = max(res, end - start + 1);         
        }
        return res;
    }
};