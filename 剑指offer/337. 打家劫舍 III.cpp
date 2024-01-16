
// 方法一：树形dp
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
    pair<int, int> dfs(TreeNode* root) {
        if(root == nullptr) return {0, 0}; //没有节点，怎么选都是0
        auto [l_rob, l_not_rob] = dfs(root->left); 
        auto [r_rob, r_not_rob] = dfs(root->right);
        int rob = l_not_rob + r_not_rob + root->val; // 选
        int not_rob = max(l_rob, l_not_rob) + max(r_rob, r_not_rob); // 不选
        return {rob, not_rob};
    }
    int rob(TreeNode* root) {
        auto [rob, not_rob] = dfs(root);
        return max(rob, not_rob);
    }
};

// 方法二：记忆化搜索
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
    unordered_map<TreeNode*, int> memo; 
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        if(memo.count(root)) return memo[root];
        int rob = root->val + (root->left == nullptr? 0:dfs(root->left->left) + dfs(root->left->right)) + (root->right == nullptr? 0:dfs(root->right->left) + dfs(root->right->right));
        int not_rob = dfs(root->left) + dfs(root->right);
        int res = max(rob, not_rob);
        memo[root] = res;
        return res;
    }
    int rob(TreeNode* root) {
        return dfs(root);
    }
};