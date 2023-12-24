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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        int maxnum = nums[0];
        int ind = 0;
        for(int i = 0; i<n; i++){
            if(maxnum < nums[i]) {
                maxnum = nums[i];
                ind = i;
            }
        }
        TreeNode* root = new TreeNode(maxnum);
        if(ind > 0){
            vector<int> left(nums.begin(), nums.begin()+ind);
            root->left = constructMaximumBinaryTree(left);
        }
        if(ind < n-1) {
            vector<int> right(nums.begin()+ind+1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};