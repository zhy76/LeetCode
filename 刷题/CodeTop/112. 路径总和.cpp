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
    bool backtrack(TreeNode* root, int targetSum, int sum) {
        if(root == nullptr) return false;
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr && sum == targetSum) {
            return true;
        }
        bool left = backtrack(root->left, targetSum, sum);
        bool right = backtrack(root->right, targetSum, sum);
        sum -= root->val;
        // cout<<sum << endl;
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return backtrack(root, targetSum, 0);
    }
};