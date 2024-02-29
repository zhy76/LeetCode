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
    unordered_map<long long, int> prefix; // 前缀和对应的次数

    int dfs(TreeNode* root, long long cur, int targetSum) {
        if(root == nullptr) return 0;
        cur += root->val;
        int ret = 0;
        if(prefix.count(cur - targetSum)) {
            ret = prefix[cur - targetSum];
        }
        prefix[cur]++;
        ret += dfs(root->left, cur, targetSum);
        ret += dfs(root->right, cur, targetSum);
        prefix[cur]--;
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};