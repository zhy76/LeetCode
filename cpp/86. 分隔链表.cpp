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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1=new ListNode(-1);
        ListNode* head2=new ListNode(-1);
        ListNode *less=head1, *great=head2;
        ListNode* p=head;
        while(p!=nullptr){
            if(p->val<x){
                less->next=p;
                less=p;
            } else{
                great->next=p;
                great=p;
            }
            p=p->next;
        }
        great->next=nullptr;
        less->next=head2->next;
        return head1->next;
    }
};