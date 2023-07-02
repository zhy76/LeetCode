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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=l1;
        ListNode* q=l2;
        ListNode* h=new(ListNode);
        ListNode* pre=h;
        int yu=0;
        while(p!=nullptr&&q!=nullptr){
            int t=yu+p->val+q->val;
            yu=t/10;
            ListNode* cur=new(ListNode);
            cur->val=t%10;
            cur->next=nullptr;
            pre->next=cur;
            pre=pre->next;
            p=p->next;
            q=q->next;
        }
        while(p!=nullptr){
            ListNode* cur=new(ListNode);
            int t=yu+p->val;
            cur->val=t%10;
            cur->next=nullptr;
            yu=t/10;
            pre->next=cur;
            pre=pre->next;
            p=p->next;
        }
        while(q!=nullptr){
            ListNode* cur=new(ListNode);
            int t=yu+q->val;
            cur->val=t%10;
            cur->next=nullptr;
            yu=t/10;
            pre->next=cur;
            pre=pre->next;
            q=q->next;
        }
        if(yu){
            ListNode* cur=new(ListNode);
            cur->val=yu;
            cur->next=nullptr;
            pre->next=cur;
            pre=pre->next;
        }
        return h->next;
    }
};