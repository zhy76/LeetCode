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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        bool flag = false;
        while(!qu.empty()) {
                auto cur = qu.front();
                qu.pop();
                if(cur == nullptr) flag = true;
                else {
                    if(flag) return false;
                    qu.push(cur->left);
                    qu.push(cur->right);
                }
            
            
        }
        return true;
    }
};