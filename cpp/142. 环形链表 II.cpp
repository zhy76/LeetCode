/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            slow=slow->next;
            if(fast->next==NULL){
                return NULL;
            }
            fast=fast->next->next;
            if(slow==fast){
                ListNode* p=head;
                while(slow!=p){
                    p=p->next;
                    slow=slow->next;
                }
                return p;
            }
        }
        return NULL;
    }
};