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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy, *pa = a, * pb = b;
        while(pa != nullptr || pb != nullptr) {
            if(pa == nullptr) {
                cur->next = pb;
                break;
            } 
            if(pb == nullptr) {
                cur->next = pa;
                break;
            } 
            if(pa->val < pb->val) {
                cur->next = pa;
                pa = pa->next;
            } else {
                cur->next = pb;
                pb = pb->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        int len = 0;
        ListNode* p = head;
        while(p != nullptr) {
            len++;
            p = p->next;
        }
        ListNode* dummy = new ListNode(0, head);
        for(int subLen = 1; subLen < len; subLen <<= 1) {
            ListNode* prev = dummy, *cur = dummy->next;
            while(cur != nullptr) {
                ListNode* head1 = cur;
                for(int i = 1; i < subLen && cur->next != nullptr; i++) {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for(int i = 1; i < subLen && cur != nullptr && cur->next != nullptr; i++) {
                    cur = cur->next;
                }
                ListNode* next = nullptr;
                if(cur != nullptr) {
                    next = cur->next;
                    cur->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while(prev->next != nullptr) {
                    prev = prev->next;
                }
                cur = next;
            }
        }
        return dummy->next;

    }
};