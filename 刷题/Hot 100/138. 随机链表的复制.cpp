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
        unordered_map<int, int> index_randomInd;// index: random index
        unordered_map<int, Node*> mp;//index: new Node*
        unordered_map<Node*, int> node_index; // old Node*: index;
        Node* p1=head;
        Node* dummyHead = new Node(0);
        Node* p2=dummyHead;
        int i=0;
        while(p1!=NULL){
            node_index[p1] = i;
            p1=p1->next;
            i++;
        }
        i=0;
        p1=head;
        while(p1!=NULL){
            Node* tmp = new Node(p1->val);
            mp[i] = tmp;
            p2->next = tmp;
            if(p1->random == NULL) index_randomInd[i] = -1;
            else index_randomInd[i]=node_index[p1->random];
            p1=p1->next;
            p2=p2->next;
            i++;
        }
        i=0;
        p2=dummyHead->next;
        while(p2!=NULL){
            if(index_randomInd[i] == -1) p2->random == NULL;
            else p2->random = mp[index_randomInd[i]];
            p2=p2->next;
            i++;
        }
        return dummyHead->next;
    }
};

// 法2：
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
        if(head == NULL) return NULL;
        unordered_map<Node*, Node*> mp; // old Node*: new Node*
        Node* p=head;
        while(p!=NULL){
            Node* newNode = new Node(p->val);
            mp[p] = newNode;
            p=p->next;
        }
        p=head;
        while(p!=NULL){
            mp[p]->next=mp[p->next];
            mp[p]->random=mp[p->random];
            p=p->next;
        }
        return mp[head];
    }
};