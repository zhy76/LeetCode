/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* p;
    TreeNode* buildTree(TreeNode* root, int left, int right) {
        if(left > right) return nullptr;
        int mid = left + (right - left) / 2;
        root = new TreeNode(0);
        TreeNode* leftnode = buildTree(root->left, left, mid - 1);
        root->val = p->val;
        p = p->next;
        TreeNode* rightnode = buildTree(root->right, mid + 1, right);
        root->left = leftnode;
        root->right = rightnode;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        p = head;
        ListNode* cur = head;
        int len = 0;
        while(cur != nullptr) {
            cur = cur->next;
            len++;
        }
        TreeNode* root;
        return buildTree(root, 0, len - 1);
    }
};