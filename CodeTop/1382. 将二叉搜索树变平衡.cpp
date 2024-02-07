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
    vector<int> nums;
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(vector<int> nums, int left, int right) {
        if(left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, left, mid - 1);
        root->right = build(nums, mid + 1, right);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(nums, 0, nums.size() - 1);
    }
};