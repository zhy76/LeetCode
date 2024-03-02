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
    Node* pre = NULL;
    Node* head = new Node(-1);
    // Node* tail = NULL;
    void inorder(Node* root) {
        if(root == NULL) {
            return;
        }
        inorder(root->left);
        if(pre) {
            root->left = pre;
            pre->right = root;
        } else {
            head->right = root;
            root->left = head;
        }
        pre = root;
        inorder(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root == NULL) return root;
        inorder(root);
        pre->right = head->right;
        head->right->left = pre;
        return head->right;
    }
};