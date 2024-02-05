/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* p = head;
        while(p != NULL) {
            Node* newNode = new Node(p->val);
            mp[p] = newNode;
            p = p->next;
        }
        p = head;
        while(p != NULL) {
            Node* oldRandom = p->random;
            Node* oldNext = p->next;
            Node* newRandom = mp[oldRandom];
            Node* newNext = mp[oldNext];
            mp[p]->random = newRandom;
            mp[p]->next = newNext;
            p = p->next;
        }
        return mp[head];
    }
};