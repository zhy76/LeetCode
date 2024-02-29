// 方法一：DFS
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
    int rootSum(TreeNode* root, long targetSum) {
        if(root == nullptr) {
            return 0;
        }
        int ret = 0;
        if(root->val == targetSum) {
            ret++;
        }
        ret+=rootSum(root->left, targetSum - root->val);
        ret+=rootSum(root->right, targetSum - root->val);
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        int ret = rootSum(root, targetSum);
        ret+=pathSum(root->left, targetSum);
        ret+=pathSum(root->right, targetSum);
        return ret;
    }
};

// 方法二： 前缀和 + 回溯

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
    unordered_map<long long, int> prefix;
    int backtrack(TreeNode* root, long long cur, int targetSum) {
        if(root == nullptr) {
            return 0;
        }
        int ret = 0;
        cur += root->val;
        if(prefix.count(cur - targetSum)) {
            ret = prefix[cur - targetSum];
        }

        prefix[cur]++;
        ret += backtrack(root->left, cur, targetSum);
        ret += backtrack(root->right, cur, targetSum);
        prefix[cur]--;
        return ret;
    }
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return backtrack(root, 0, targetSum);
    }
};