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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int depth = 1;
        while(!qu.empty()){
            int sz = qu.size();
            for(int i=0; i<sz; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                if(node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
                if(node->left != nullptr) {
                    qu.push(node->left);
                }
                if(node->right !=nullptr) {
                    qu.push(node->right);
                }
            }
            depth++;
        }
        return depth;
    }
};