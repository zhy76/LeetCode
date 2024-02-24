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
    vector<vector<int>> res;
    vector<int> track;
    void backtrack(TreeNode* root, int targetSum, int sum) {
        if(root == nullptr) { 
            return;
        }
        track.push_back(root->val);
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr && sum == targetSum) {
            res.push_back(track);
            track.pop_back();
            sum -= root->val;
            return;
        }
        backtrack(root->left, targetSum, sum);
        backtrack(root->right, targetSum, sum);
        sum -= root->val;
        track.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return res;
        backtrack(root, targetSum, 0);
        return res;
    }
};