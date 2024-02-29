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
        ListNode* p = l1, *q = l2;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int carry = 0;
        while(p!=nullptr && q!= nullptr) {
            int a = p->val;
            int b = q->val;
            int sum = a+b+carry;
            cout<<sum<<endl;
            carry = sum/10;
            ListNode* tmp = new ListNode(sum%10);
            cur->next = tmp;
            cur = cur->next;
            p = p->next;
            q = q->next;
        }
        while(p != nullptr) {
            int sum = p->val + carry;
            carry = sum/10;
            ListNode* tmp = new ListNode(sum%10);
            cur->next = tmp;
            cur=cur->next;
            p=p->next;
        }
        while(q != nullptr) {
            int sum = q->val + carry;
            carry = sum/10;
            ListNode* tmp = new ListNode(sum%10);
            cur->next = tmp;
            cur=cur->next;
            q=q->next;
        }
        if(carry!=0) {
            ListNode* tmp = new ListNode(carry);
            cur->next = tmp;
        }
        return dummy->next;
    }
};