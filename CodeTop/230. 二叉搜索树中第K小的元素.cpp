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
    unordered_map<TreeNode*, int> nodeNum;
    int count(TreeNode* root) {
        if(root == nullptr) return 0;
        nodeNum[root] = count(root->left) + count(root->right) + 1;
        return nodeNum[root];
    }

    int getNodeNum(TreeNode* root) {
        if(root != nullptr && nodeNum.count(root)) {
            return nodeNum[root];
        }
        return 0;
    }

    int getK(TreeNode* root, int k) {
        if(root == nullptr) return -1;
        int leftNum = getNodeNum(root->left);
        if(leftNum + 1 == k) return root->val;
        else if(leftNum + 1 < k) return getK(root->right, k - leftNum - 1);
        else return getK(root->left, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        count(root);
        return getK(root, k);
    }
};