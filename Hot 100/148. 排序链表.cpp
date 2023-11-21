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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next ==nullptr) return head;
        ListNode* slow=head, *fast=head,*mid=head;
        while(fast!=nullptr && fast->next!=nullptr){
            mid=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        mid->next=nullptr;

        ListNode* l=sortList(head);
        ListNode* r=sortList(slow);

        return merge(l,r);
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* p1=head1, *p2=head2,*p3=dummy;
        while(p1 != nullptr && p2 !=nullptr) {
            if(p1->val <= p2->val){
                p3->next=p1;
                p1=p1->next;
            } else {
                p3->next=p2;
                p2=p2->next;
            }
            p3=p3->next;
        }
        if(p1!=nullptr){
            p3->next = p1;
        } else if(p2!=nullptr) {
            p3->next = p2;
        }
        return dummy->next;
    }
    
};