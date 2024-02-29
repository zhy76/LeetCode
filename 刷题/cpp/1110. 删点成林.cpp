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
    vector<TreeNode*> ans;
    bool check(TreeNode* root,vector<int>& to_delete){
        for(auto v:to_delete){
            if(v==root->val){
                return true;
            }
        }
        return false;
    }
    TreeNode* dfs(TreeNode* root,vector<int>& to_delete,bool is_root){
        if(root==nullptr){
            return nullptr;
        }
        bool deleted=check(root,to_delete);
        root->left=dfs(root->left,to_delete,deleted);
        root->right=dfs(root->right,to_delete,deleted);
        
        if(deleted){
            root=nullptr;
        }else{
            if(is_root){
                ans.push_back(root);
            }
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        dfs(root,to_delete,true);
        return ans;
    }
};