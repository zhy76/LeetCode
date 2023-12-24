/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void traverse(Node* node1, Node* node2){
        if(node1 == NULL || node2 == NULL) {
            return;
        } 
        node1->next = node2;
        traverse(node1->left, node1->right);
        traverse(node2->left, node2->right);

        traverse(node1->right, node2->left);
    }
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        traverse(root->left, root->right);
        return root;
    }
};