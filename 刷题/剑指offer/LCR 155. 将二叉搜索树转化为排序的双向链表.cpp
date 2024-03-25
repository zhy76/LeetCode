/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* pre = NULL, *head = NULL;
    void inorder(Node* root) {
        if(root == NULL) return;
        inorder(root->left);
        if(pre != NULL) {
            pre->right = root;
        } else {
            head = root;
        }
        root->left = pre;
        pre = root;
        inorder(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return NULL;
        inorder(root);
        pre->right = head;
        head->left = pre;
        return head;
    }
};