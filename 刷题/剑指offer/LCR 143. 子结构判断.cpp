/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, TreeNode* B) {
        if(B == NULL) return true;
        if(root == NULL || root->val != B->val) {
            return false;
        }
        bool left = check(root->left, B->left);
        bool right = check(root->right, B->right);
        return left && right;
    }
    
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A != NULL && B!=NULL) && (check(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
};


// 2024/3/25
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* a, TreeNode* b) {
        if(b == NULL) return true;
        if(a == NULL || a->val != b->val) return false;
        bool left = check(a->left, b->left);
        bool right = check(a->right, b->right);
        return left && right;
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL) return false;
        bool flag = check(A, B);
        bool left = isSubStructure(A->left, B);
        bool right = isSubStructure(A->right, B);
        return flag || left || right; 
    }
};