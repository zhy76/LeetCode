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
class MyBst {
private:
    TreeNode* root;
    unordered_map<TreeNode*, int> nodeNum;

    int countNodeNum(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }
        nodeNum[node] = 1 + countNodeNum(node->left) + countNodeNum(node->right);
        return nodeNum[node];
    }
    int getNodeNum(TreeNode* node) {
        if(node != nullptr && nodeNum.count(node)) {
            return nodeNum[node];
        } else return 0;
    }
public:
    MyBst(TreeNode* root) {
        this->root = root;
        countNodeNum(root);
    }

    int kthSmallest(int k) {
       TreeNode *node = root;
       while(node!=nullptr) {
           int left = getNodeNum(node->left);
           if(left < k-1) {
               node = node->right;
               k -= left + 1;
           } else if(left == k-1) {
               break;
           } else {
               node = node->left;
           }
       }
       return node->val;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        MyBst bst(root);
        return bst.kthSmallest(k);
    }
};
