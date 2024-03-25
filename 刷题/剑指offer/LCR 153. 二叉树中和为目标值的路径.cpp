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
    vector<int> track;
    vector<vector<int>> res;
    void backtrack(TreeNode* root, int target, int sum) {
        if(root->left == nullptr && root->right == nullptr) {
            if(sum == target) {
                res.push_back(track);
            }
            return;
        }
        
        if(root->left) {
            track.push_back(root->left->val);
            sum += root->left->val;
            backtrack(root->left, target, sum);
            track.pop_back();
            sum -= root->left->val;
        }
        
        if(root->right) {
            track.push_back(root->right->val);
            sum += root->right->val;
            backtrack(root->right, target, sum);
            track.pop_back();
            sum -= root->right->val;
        }
        
    }
    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        if(root == nullptr) return res;
        track.push_back(root->val);
        backtrack(root, target, root->val);
        track.pop_back();
        return res;
    }
};