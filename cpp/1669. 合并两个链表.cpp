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
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p=list1;
        int ind=0;
        ListNode* A=nullptr;
        ListNode* B=nullptr;
        while(p->next!=nullptr){
            if(ind==a-1){
                A=p;
            }
            if(ind==b){
                B=p;
            }
            p=p->next;
            ind++;
        }
        A->next=list2;
        ListNode* q=list2;
        while(q->next!=nullptr){
            q=q->next;
        }
        q->next=B->next;
        return list1;
    }
};