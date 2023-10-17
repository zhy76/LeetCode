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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p=list1;
        ListNode* q=list2;
        ListNode* list3=new ListNode();
        ListNode* cur=list3;
        while(p!=nullptr && q!=nullptr){
            if(p->val<q->val){
                ListNode* t=new ListNode(p->val);
                cur->next=t;
                cur=t;
                p=p->next;
            }else{
                ListNode* t=new ListNode(q->val);
                cur->next=t;
                cur=t;
                q=q->next;
            }
        }
        while(p!=nullptr){
            ListNode* t=new ListNode(p->val);
            cur->next=t;
            cur=t;
            p=p->next;
        }
        while(q!=nullptr){
            ListNode* t=new ListNode(q->val);
            cur->next=t;
            cur=t;
            q=q->next;
        }
        return list3->next;
    }
};